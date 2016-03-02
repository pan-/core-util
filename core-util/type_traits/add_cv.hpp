#ifndef MBED_CORE_UTIL_TYPE_TRAITS_ADD_CV_HPP_
#define MBED_CORE_UTIL_TYPE_TRAITS_ADD_CV_HPP_

namespace mbed { namespace type_traits {

template<class T>
struct add_cv {
    using type = const volatile T;
};

template<typename T>
using add_cv_t = typename add_cv<T>::type;

template<class T>
struct add_const {
    using type = const T;
};

template<typename T>
using add_const_t = typename add_const<T>::type;

template<class T>
struct add_volatile {
    using type = volatile T;
};

template<typename T>
using add_volatile_t = typename add_volatile<T>::type;

}} // namespace mbed::type_traits

#endif /* MBED_CORE_UTIL_TYPE_TRAITS_ADD_CV_HPP_ */
