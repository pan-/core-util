#ifndef MBED_TYPE_TRAITS_ENABLE_IF_H_
#define MBED_TYPE_TRAITS_ENABLE_IF_H_

namespace mbed { namespace type_traits {

template<bool B, typename T = void>
struct enable_if;

template<typename T>
struct enable_if<true, T> {
    using type = T;
};

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

}} // mbed::type_traits

#endif /* MBED_TYPE_TRAITS_ENABLE_IF_H_ */
