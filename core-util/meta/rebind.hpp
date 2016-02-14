#ifndef MBED_META_REBIND_H_
#define MBED_META_REBIND_H_

namespace mbed { namespace meta {

template<typename Src, template<typename...> class Dest>
struct rebind;

template<template<typename...> class C, typename... Ts, template<typename...> class Dest>
struct rebind<C<Ts...>, Dest> {
    using type = Dest<Ts...>;
};

template<typename Src, template<typename...> class Dest>
using rebind_t = typename rebind<Src, Dest>::type;

}} // namespace mbed::meta

#endif /* MBED_META_REBIND_H_ */
