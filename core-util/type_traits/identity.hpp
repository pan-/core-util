#ifndef MBED_TYPE_TRAITS_IDENTITY_H_
#define MBED_TYPE_TRAITS_IDENTITY_H_

namespace mbed { namespace type_traits {

template<typename T>
struct identity {
    using type = T;
};

template<typename T>
using identity_t = typename identity<T>::type;

}} // namespace mbed::type_traits

#endif /* MBED_TYPE_TRAITS_IDENTITY_H_ */
