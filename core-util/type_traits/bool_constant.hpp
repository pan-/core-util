#ifndef MBED_TYPE_TRAITS_BOOL_CONSTANT_H_
#define MBED_TYPE_TRAITS_BOOL_CONSTANT_H_

#include "integral_constant.hpp"

namespace mbed { namespace type_traits {

/// Wraper of static boolean constants
template<bool V>
using bool_constant = integral_constant<bool, V>;

/// Type representation of the boolean constant true
using true_type = bool_constant<true>;

/// Type representation of the boolean constant false
using false_type = bool_constant<false>;

}} // namespace mbed::type_traits

#endif /* MBED_TYPE_TRAITS_BOOL_CONSTANT_H_ */
