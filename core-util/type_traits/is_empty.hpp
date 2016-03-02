#ifndef MBED_TYPE_TRAITS_IS_EMPTY_H_
#define MBED_TYPE_TRAITS_IS_EMPTY_H_

#include "bool_constant.hpp"
#include "identity.hpp"
#include "is_class.hpp"

namespace mbed { namespace type_traits {

namespace detail {

struct is_empty_tester_base {
    char data[128];
};

template<typename T>
struct is_empty_tester : public is_empty_tester_base, public T { };

template<typename T, bool is_class = is_class<T>::value>
struct is_empty_impl : public false_type {};

template<typename T>
struct is_empty_impl<T, true> :
    public bool_constant<
        sizeof(is_empty_tester_base) == sizeof(is_empty_tester<T>)
    >
{};

}

template<typename T>
struct is_empty : public detail::is_empty_impl<T> { };

template<typename T>
using is_empty_t = typename is_empty<T>::type;

}} // namespace mbed::type_traits

#endif /* MBED_TYPE_TRAITS_IS_EMPTY_H_ */
