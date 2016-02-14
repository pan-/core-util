#ifndef MBED_META_APPLY_H_
#define MBED_META_APPLY_H_

#include "rebind.hpp"

namespace mbed { namespace meta {

//
template<template<typename...> class F, class S>
struct apply {
    using type = rebind_t<S, F>;
};

template<template<typename...> class F, class S>
using apply_t = rebind_t<S, F>;

}} // namespace mbed::meta

#endif /* MBED_META_APPLY_H_ */
