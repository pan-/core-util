#ifndef MBED_CORE_UTIL_DETAIL_TUPLE_HPP_
#define MBED_CORE_UTIL_DETAIL_TUPLE_HPP_

#include <cstdint>
#include <type_traits/integral_constant.hpp>

// forward declaration of tuple
namespace mbed {
template<typename... Ts>
class tuple;
}

namespace mbed { namespace detail {

template<class T>
class tuple_size;

template<class... Ts>
class tuple_size<tuple<Ts...>> :
    public type_traits::integral_constant<std::size_t, sizeof...(Ts)> {
};

template<class T>
class tuple_size<const T> :
    public type_traits::integral_constant<std::size_t, tuple_size<T>::value> {
};

template<class T>
class tuple_size<volatile T> :
    public type_traits::integral_constant<std::size_t, tuple_size<T>::value> {
};

template<class T>
class tuple_size<const volatile T> :
    public type_traits::integral_constant<std::size_t, tuple_size<T>::value> {
};

}} // namespace mbed::detail

#endif /* MBED_CORE_UTIL_DETAIL_TUPLE_HPP_ */
