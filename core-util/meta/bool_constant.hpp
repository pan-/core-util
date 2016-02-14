#ifndef MBED_META_BOOL_CONSTANT_H_
#define MBED_META_BOOL_CONSTANT_H_

#include "integral_constant.hpp"

namespace mbed { namespace meta {

/// Wraper of static boolean constants
template<bool V>
using bool_constant = integral_constant<bool, V>;

/// Type representation of the boolean constant true
using true_type = bool_constant<true>;

/// Type representation of the boolean constant false
using false_type = bool_constant<false>;

}} // namespace mbed::meta

#endif /* MBED_META_BOOL_CONSTANT_H_ */
