#ifndef MBED_META_TRANSFORM_H_
#define MBED_META_TRANSFORM_H_

#include "push_front.hpp"

namespace mbed { namespace meta {

template<typename Seq, template<typename> class F>
struct transform;

template<typename Seq, template<typename> class F>
using transform_t = typename transform<Seq, F>::type;

template<template<typename...> class C, template<typename> class F>
struct transform<C<>, F> {
    using type = C<>;
};

template<template<typename...> class C, typename Head, typename... Ts, template<typename> class F>
struct transform<C<Head, Ts...>, F> {
    using type = push_front_t<
        transform_t<C<Ts...>, F>,
        F<Head>
    >;
};

}} // namespace mbed::meta

#endif /* MBED_META_TRANSFORM_H_ */
