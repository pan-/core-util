#ifndef MBED_CORE_UTIL_DETAIL_TUPLE_LEAF_H_
#define MBED_CORE_UTIL_DETAIL_TUPLE_LEAF_H_

#include <cstdint>
#include "utility/forward.hpp"
#include "type_traits/is_empty.hpp"

namespace mbed { namespace detail {

template<std::size_t Index, typename T, typename tag = type_traits::is_empty_t<T>>
struct tuple_leaf;

template<std::size_t Index, typename T>
struct tuple_leaf<Index, T, type_traits::false_type> {

    constexpr tuple_leaf() : value() {}

    template<typename U>
    constexpr tuple_leaf(U&& v) : value(utility::forward<U>(v)) {}

    T& get() & {
        return value;
    }

    T&& get() && {
        return static_cast<T&&>(value);
    }

    constexpr const T& get() const & {
        return value;
    }

    constexpr const T&& get() const && {
        return static_cast<const T&&>(value);
    }

private:
    T value;
};


template<std::size_t Index, typename T>
struct tuple_leaf<Index, T, type_traits::true_type> : private T {

    constexpr tuple_leaf(): T()  {}

    template<typename U>
    constexpr tuple_leaf(U&& v) : T(utility::forward<U>(v)) {}

    T& get() & {
        return *static_cast<T*>(this);
    }

    T&& get() && {
        return *static_cast<T*>(this);
    }

    constexpr const T& get() const & {
        return *static_cast<T*>(this);
    }

    constexpr const T&& get() const && {
        return *static_cast<T*>(this);
    }
};

}} // namespace mbed::detail

#endif /* MBED_CORE_UTIL_DETAIL_TUPLE_LEAF_H_ */
