#ifndef MBED_UTILITY_FORWARD_H_
#define MBED_UTILITY_FORWARD_H_

#include "type_traits/remove_reference.hpp"

namespace mbed { namespace utility {

template<typename T>
constexpr T&& forward(type_traits::remove_reference_t<T>& val) noexcept {
    return static_cast<T&&>(val);
}

template<typename T>
constexpr T&& forward(type_traits::remove_reference_t<T>&& val) noexcept {
    return static_cast<T&&>(val);
}

}} // namespace mbed::utility

#endif /* MBED_UTILITY_FORWARD_H_ */
