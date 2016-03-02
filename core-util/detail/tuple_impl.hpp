#ifndef MBED_CORE_UTIL_DETAIL_TUPLE_IMPL_H_
#define MBED_CORE_UTIL_DETAIL_TUPLE_IMPL_H_

#include "meta/integer_sequence.hpp"
#include "meta/at.hpp"
#include "meta/sequence.hpp"
#include "utility/forward.hpp"
#include "tuple_leaf.hpp"

#include "meta/box.hpp"
#include "meta/box_integer_sequence.hpp"
#include "meta/zip.hpp"
#include "meta/unzip.hpp"
#include "meta/transform.hpp"
#include "meta/sort.hpp"

namespace mbed { namespace detail {

struct regular_construct_tag {};

struct reorder_construct_tag {};

template<class Indices, typename Seq>
struct tuple_impl_base;

template<
    template<typename...> class Cont, typename... Ts,
    typename... Indices>
struct tuple_impl_base<meta::sequence<Indices...>, Cont<Ts...>> : tuple_leaf<Indices::value, Ts>... {

    constexpr tuple_impl_base() : tuple_leaf<Indices::value, Ts>()... {}

    template<typename... Us>
    constexpr tuple_impl_base(regular_construct_tag, Us&&... values) :
        tuple_leaf<Indices::value, Ts>(utility::forward<Us>(values))... {}

    template<typename I, template<typename...> class C, typename... Us>
    constexpr tuple_impl_base(reorder_construct_tag, tuple_impl_base<I, C<Us...>> values) :
        tuple_leaf<Indices::value, Ts>(
            utility::forward<meta::at_t<C<Us&&...>, Indices::value>>(
                values.template get<Indices::value, meta::at_t<meta::sequence<Us&&...>, Indices::value>>()
            )
        )... {
    }

    template<std::size_t index, typename T>
    T& get() & {
        return tuple_leaf<index, T>::get();
    }

    template<std::size_t index, typename T>
    T&& get() && {
        return tuple_leaf<index, T>::get();
    }

    template<std::size_t index, typename T>
    constexpr const T& get() const &  {
        return tuple_leaf<index, T>::get();
    }

    template<std::size_t index, typename T>
    constexpr T&& get() const && {
        return static_cast<const tuple_leaf<index, T>&&>(*this).get();
    }
};


template<typename... Ts>
struct reorder {
    using indexed_sequence = meta::zip_t<
        meta::box_integer_sequence_t<meta::index_sequence_for<Ts...>>,
        meta::sequence<Ts...>
    >;

    template<typename L, typename R>
    using alignof_lt = type_traits::bool_constant<(alignof(typename L::second_type) > alignof(typename R::second_type))>;

    using sorted_sequence = meta::sort_t<indexed_sequence, alignof_lt>;
    using indices = typename meta::unzip_t<sorted_sequence>::first_type;
    using types = typename meta::unzip_t<sorted_sequence>::second_type;
};


template<typename... Ts>
class tuple_impl : public tuple_impl_base<
    typename detail::reorder<Ts...>::indices,
    typename detail::reorder<Ts...>::types
> {

    using reordered_indices = typename detail::reorder<Ts...>::indices;

    using impl_type = tuple_impl_base<
        reordered_indices,
        typename detail::reorder<Ts...>::types
    >;

public:
    constexpr tuple_impl() { }

    template<typename... Us>
    constexpr tuple_impl(Us&&... values) :
        impl_type(
            detail::reorder_construct_tag {},
            tuple_impl_base<
                meta::box_integer_sequence_t<meta::index_sequence_for<Ts...>>,
                meta::sequence<Us&&...>
            >(detail::regular_construct_tag {}, utility::forward<Us&&>(values)...)
        ) {
    }
};



}} // namespace mbed::detail

#endif /* MBED_CORE_UTIL_DETAIL_TUPLE_IMPL_H_ */
