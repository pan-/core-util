#ifndef MBED_TYPE_TRAITS_IS_CONVERTIBLE_H_
#define MBED_TYPE_TRAITS_IS_CONVERTIBLE_H_

#include "bool_constant.hpp"
#include "identity.hpp"

namespace mbed { namespace type_traits {

namespace detail {

template<typename T>
T is_convertible_make_value();

template<typename T>
constexpr true_type is_convertible_checker(T) {
    return true_type {};
}

template<typename T>
constexpr false_type is_convertible_checker(...) {
    return false_type {};
}

}

template<typename From, typename To>
struct is_convertible : public identity_t<
    decltype(detail::is_convertible_checker<To>(detail::is_convertible_make_value<From>()))
> { };

template<typename From, typename To>
using is_convertible_t = typename is_convertible<From, To>::type;

}} // namespace mbed::type_traits


#endif /* MBED_TYPE_TRAITS_IS_CONVERTIBLE_H_ */
