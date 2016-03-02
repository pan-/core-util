/*
 * zip.hpp
 *
 *  Created on: 26 Feb 2016
 *      Author: vincou01
 */

#ifndef META_ZIP_HPP_
#define META_ZIP_HPP_

#include "pair.hpp"
#include "sequence.hpp"

namespace mbed { namespace meta {

template<typename Ts, typename Us>
struct zip;

template<template<typename...> class TsCont, typename... Ts, template<typename...> class UsCont, typename... Us>
struct zip<TsCont<Ts...>, UsCont<Us...>> {
    static_assert(sizeof...(Ts) == sizeof...(Us), "the two list in input should have the same size");

    using type = sequence<pair<Ts, Us>...>;
};

template<typename Ts, typename Us>
using zip_t = typename zip<Ts, Us>::type;

}} // namespace mbed::meta

#endif /* META_ZIP_HPP_ */
