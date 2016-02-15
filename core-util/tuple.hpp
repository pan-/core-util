#ifndef MBED_TUPLE_H_
#define MBED_TUPLE_H_

#include <cstdint>

#include "detail/tuple_impl.hpp"
#include "meta/sequence.hpp"
#include "meta/integer_sequence.hpp"
#include "meta/make_integer_sequence.hpp"
#include "utility/forward.hpp"
#include "meta/transform.hpp"
#include "meta/sort.hpp"
#include "type_traits/bool_constant.hpp"

namespace mbed {

namespace detail {

template<std::size_t index, typename T>
struct indexed_element {
    static constexpr std::size_t index_value = index;
    using element_type = T;
};

template<typename Indices, typename... Ts>
struct make_indexed_sequence_impl;

template<std::size_t... Indices, typename... Ts>
struct make_indexed_sequence_impl<meta::index_sequence<Indices...>, Ts...> {
    using type = meta::sequence<indexed_element<Indices, Ts>...>;
};

// return a list of indexed elements
template<typename... Ts>
struct make_indexed_sequence {
    using type = typename make_indexed_sequence_impl<meta::index_sequence_for<Ts...>, Ts...>::type;
};

template<typename... Ts>
using make_indexed_sequence_t = typename make_indexed_sequence<Ts...>::type;


template<typename L, typename R>
struct alignof_lt :
    public type_traits::bool_constant<(alignof(typename L::element_type) > alignof(typename R::element_type))> { };

template<typename L, typename R>
struct append_index_sequence;

template<size_t... LIndices, size_t... RIndices>
struct append_index_sequence<
    meta::index_sequence<LIndices...>,
    meta::index_sequence<RIndices...>
> {
    using type = meta::index_sequence<LIndices..., RIndices...>;
};

template<typename L, typename R>
using append_index_sequence_t = typename append_index_sequence<L, R>::type;


template<typename T>
struct extract_index_sequence;

template<template<typename...> class C>
struct extract_index_sequence<C<>> {
    using type = meta::index_sequence<>;
};

template<template<typename...> class C, typename Head, typename... Ts>
struct extract_index_sequence<C<Head, Ts...>> {
    using type = append_index_sequence_t<
        meta::index_sequence<Head::index_value>,
        typename extract_index_sequence<C<Ts...>>::type
    >;
};

template<typename T>
using extract_index_sequence_t = typename extract_index_sequence<T>::type;


template<typename T>
using get_element_type_t = typename T::element_type;

template<typename Seq>
using extract_types_t = meta::transform_t<Seq, get_element_type_t>;



template<typename... Ts>
struct reorder {
    using indexed_sequence = make_indexed_sequence_t<Ts...>;
    using sorted_sequence = meta::sort_t<indexed_sequence, alignof_lt>;
    using indices = extract_index_sequence_t<sorted_sequence>;
    using types = extract_types_t<sorted_sequence>;
};


template<typename S, std::size_t index>
struct index_sequence_at;

template<std::size_t Head, std::size_t... Tail, std::size_t index>
struct index_sequence_at<meta::index_sequence<Head, Tail...>, index> {
    static constexpr std::size_t value =
        index_sequence_at<meta::index_sequence<Tail...>, index - 1>::value;
};

template<std::size_t Head, std::size_t... Tail>
struct index_sequence_at<meta::index_sequence<Head, Tail...>, 0> {
    static constexpr std::size_t value = Head;
};

}








template<typename... Ts>
class tuple : public detail::tuple_impl<
    meta::index_sequence_for<Ts...>,
    typename detail::reorder<Ts...>::types
> {

    using reordered_indices = typename detail::reorder<Ts...>::indices;

    using impl_type = detail::tuple_impl<
        meta::index_sequence_for<Ts...>,
        typename detail::reorder<Ts...>::types
    >;

public:
    constexpr tuple() { }

    template<typename... Us>
    constexpr tuple(Us&&... values) :
        impl_type(
            reordered_indices {},
            detail::tuple_impl<
                meta::index_sequence_for<Ts...>,
                meta::sequence<Us&&...>
            >(detail::piecewise_construct_t(), utility::forward<Us>(values)...)
        ) {
    }


    template<std::size_t Index>
    auto get() -> meta::at_t<meta::sequence<Ts...>, Index>& {
        return impl_type::template get<detail::index_sequence_at<reordered_indices, Index>::value>();
    }

    template<std::size_t Index>
    auto get() const -> const meta::at_t<meta::sequence<Ts...>, Index>& {
        return impl_type::template get<detail::index_sequence_at<reordered_indices, Index>::value>();
    }
};


template<typename... Ts>
constexpr tuple<Ts&&...> forward_as_tuple(Ts&&... args) {
    return tuple<Ts&&...>(utility::forward<Ts>(args)...);
}

} // namespace mbed


#endif /* MBED_TUPLE_H_ */
