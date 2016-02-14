#ifndef MBED_META_ENABLE_IF_H_
#define MBED_META_ENABLE_IF_H_

namespace mbed { namespace meta {

template<bool B, typename T = void>
struct enable_if;

template<typename T>
struct enable_if<true, T> {
    using type = T;
};

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

}} // mbed::meta

#endif /* MBED_META_ENABLE_IF_H_ */
