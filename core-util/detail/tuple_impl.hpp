#include "meta/integer_sequence.hpp"
#include "meta/at.hpp"
#include "meta/sequence.hpp"
#include "utility/forward.hpp"

namespace mbed { namespace detail {

/// TODO : use EBCO
template<std::size_t Index, typename T>
struct tuple_leaf {

    constexpr tuple_leaf() : value() {}

    template<typename U>
    constexpr tuple_leaf(U&& v) : value(utility::forward<U>(v)) {}

    T& get() {
        return value;
    }

    constexpr T& get() const {
        return value;
    }

private:
    T value;
};

struct piecewise_construct_t {};


template<class Indices, typename Seq>
struct tuple_impl;

template<
    template<typename...> class Cont, typename... Ts,
    std::size_t... Indices>
struct tuple_impl<meta::index_sequence<Indices...>, Cont<Ts...>> : tuple_leaf<Indices, Ts>... {

    constexpr tuple_impl() : tuple_leaf<Indices, Ts>()... {}

    template<typename... Us>
    constexpr tuple_impl(piecewise_construct_t, Us&&... values) :
        tuple_leaf<Indices, Ts>(utility::forward<Us>(values))... {}

    template<std::size_t... Mapping, typename I, template<typename...> class C, typename... Us>
    constexpr tuple_impl(meta::index_sequence<Mapping...>, tuple_impl<I, C<Us&&...>>&& values) :
        tuple_leaf<Indices, Ts>(
            utility::forward<meta::at_t<C<Us&&...>, Mapping>>(
                values.template get<Mapping>()
            )
        )... { }



    template<std::size_t index>
    auto get() -> meta::at_t<meta::sequence<Ts...>, index>& {
        return tuple_leaf<index, meta::at_t<meta::sequence<Ts...>, index>>::get();
    }

    template<std::size_t index>
    constexpr auto get() const -> const meta::at_t<meta::sequence<Ts...>, index>& {
        return tuple_leaf<index, meta::at_t<meta::sequence<Ts...>, index>>::get();
    }
};


}} // namespace mbed::detail
