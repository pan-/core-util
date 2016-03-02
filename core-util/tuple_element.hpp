#ifndef MBED_CORE_UTIL_DETAIL_TUPLE_ELEMENT_
#define MBED_CORE_UTIL_DETAIL_TUPLE_ELEMENT_

#include <cstdint>
#include <type_traits/add_cv.hpp>
#include <meta/at.hpp>

// forward declaration of tuple
namespace mbed {
template<typename... Ts>
class tuple;
}

namespace mbed {

template<std::size_t I, class T>
struct tuple_element;

template<std::size_t I, class T>
using tuple_element_t = typename tuple_element<I, T>::type;

template<std::size_t I, class... Types>
struct tuple_element<I, tuple<Types...>> {
    using type = meta::at_t<tuple<Types...>, I>;
};

template<std::size_t I, class T>
struct tuple_element<I, const T> {
    using type = type_traits::add_const_t<tuple_element_t<I, T>>;
};

template<std::size_t I, class T>
struct tuple_element<I, volatile T> {
    using type = type_traits::add_volatile_t<tuple_element_t<I, T>>;
};

template<std::size_t I, class T>
struct tuple_element<I, const volatile T> {
    using type = type_traits::add_cv_t<tuple_element_t<I, T>>;
};

} // namespace mbed

#endif /* MBED_CORE_UTIL_DETAIL_TUPLE_ELEMENT_ */
