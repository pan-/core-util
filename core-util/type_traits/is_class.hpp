#ifndef MBED_TYPE_TRAITS_IS_CLASS_H_
#define MBED_TYPE_TRAITS_IS_CLASS_H_

#include "bool_constant.hpp"
#include "identity.hpp"

namespace mbed { namespace type_traits {

namespace detail {

template<typename T>
constexpr true_type is_class_checker(void (T::*)()) { return true_type(); }

template<typename T>
constexpr false_type is_class_checker(...) { return false_type(); }

}

template<typename T>
struct is_class : public identity_t<decltype(detail::is_class_checker<T>(0))> { };

template<typename T>
using is_class_t = typename is_class<T>::type;

}} // namespace mbed::type_traits

#endif /* MBED_TYPE_TRAITS_IS_CLASS_H_ */
