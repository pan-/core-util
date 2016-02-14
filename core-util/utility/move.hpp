#ifndef MBED_UTILITY_MOVE_H_
#define MBED_UTILITY_MOVE_H_

#include "type_traits/remove_reference.hpp"

namespace mbed { namespace utility {

template<typename T>
constexpr type_traits::remove_reference_t<T>&& move(T&& val) noexcept {
    return static_cast<type_traits::remove_reference_t<T>&&>(val);
}

}} // namespace mbed::utility

#endif /* MBED_UTILITY_MOVE_H_ */
