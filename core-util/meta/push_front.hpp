#ifndef MBED_META_PUSH_FRONT_H_
#define MBED_META_PUSH_FRONT_H_

namespace mbed { namespace meta {

template<typename S, typename... Elements>
struct push_front;

template<template<class... > class  C, typename... Ts, typename... Elements>
struct push_front<C<Ts...>, Elements...> {
    using type = C<Elements..., Ts...>;
};

template<typename S, typename... Elements>
using push_front_t = typename push_front<S, Elements...>::type;

} } // mbed::meta

#endif /* MBED_META_PUSH_FRONT_H_ */
