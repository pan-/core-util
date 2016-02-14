#ifndef MBED_META_LENGTH_H_
#define MBED_META_LENGTH_H_

#include <cstdint>
#include "type_traits/integral_constant.hpp"

namespace mbed { namespace meta {

/// return the number of elements in the sequence as an integral constant
template<typename S>
struct length;

template<template<typename...> class C, typename... Ts>
struct length<C<Ts...>> {
    // this type
    using type = type_traits::integral_constant<std::size_t, sizeof...(Ts)>;
};

}} // namespace mbed::meta

#endif /* MBED_META_LENGTH_H_ */
