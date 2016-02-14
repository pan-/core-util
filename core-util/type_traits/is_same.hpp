#ifndef MBED_TYPE_TRAITS_IS_SAME_H_
#define MBED_TYPE_TRAITS_IS_SAME_H_

#include "bool_constant.hpp"

namespace mbed { namespace type_traits {

template<typename T, typename U>
struct is_same : public false_type {};

template<typename T>
struct is_same<T, T> : public true_type {};

}} // namespace mbed::type_traits

#endif /* MBED_TYPE_TRAITS_IS_SAME_H_ */
