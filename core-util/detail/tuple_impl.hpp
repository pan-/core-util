#include <type_traits>

#include "meta/integer_sequence.hpp"
#include "meta/at.hpp"
#include "meta/sequence.hpp"
#include "utility/forward.hpp"

namespace mbed { namespace detail {


/// TODO : use EBCO
template<std::size_t Index, typename T>
struct tuple_leaf {
    constexpr tuple_leaf(T&& v) : value(utility::forward<T>(v)) {}

    T& get() {
        return value;
    }

    constexpr T& get() const {
        return value;
    }

private:
    T value;
};


template<class Indices, typename... Ts>
struct tuple_impl;

template<typename... Ts, std::size_t... Indices>
struct tuple_impl<meta::index_sequence<Indices...>, Ts...> : tuple_leaf<Indices, Ts>... {

    tuple_impl(Ts&&... values) : tuple_leaf<Indices, Ts>(utility::forward<Ts>(values))... {}

    template<std::size_t index>
    auto get() -> meta::at_t<meta::sequence<Ts...>, index>& {
        return tuple_leaf<index, meta::at_t<meta::sequence<Ts...>, index>>::get();
    }

    template<std::size_t index>
    auto get() const -> const meta::at_t<meta::sequence<Ts...>, index>& {
        return tuple_leaf<index, meta::at_t<meta::sequence<Ts...>, index>>::get();
    }
};


}} // namespace mbed::detail
