#ifndef MBED_META_AT_H_
#define MBED_META_AT_H_

#include <cstdint>
#include "make_integer_sequence.hpp"

namespace mbed { namespace meta {

template<typename S, std::size_t index>
struct at;

template<template<typename...> class C, typename Head, typename... Tail, std::size_t index>
struct at<C<Head, Tail...>, index> {
    using type = typename at<C<Tail...>, index - 1>::type;
};

template<template<typename...> class C, typename Head, typename... Tail>
struct at<C<Head, Tail...>, 0> {
    using type = Head;
};

template<typename S, std::size_t index>
using at_t = typename at<S, index>::type;

}} // namespace mbed::meta

#endif /* MBED_META_AT_H_ */
