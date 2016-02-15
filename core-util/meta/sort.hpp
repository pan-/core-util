#ifndef MBED_META_SORT_H_
#define MBED_META_SORT_H_

#include "type_traits/bool_constant.hpp"
#include "push_front.hpp"
#include "filter.hpp"
#include "append.hpp"

namespace mbed { namespace meta {

/// Sort the sequence Seq with the function LessThan
template<typename Seq, template<typename...> class LessThan>
struct sort;

/// specializatio nfor empty sequence
template<template<typename...> class Cont, template<typename...> class LessThan>
struct sort<Cont<>, LessThan> {
	using type = Cont<>;
};


template<
    template<typename...> class C, typename Head, typename... Ts,
    template<typename...> class LessThan
>
struct sort<C<Head, Ts...>, LessThan> {

    // partial application of Compare with Head
	template<typename T>
	using bind_lt = LessThan<T, Head>;

	template<typename T>
	using bind_ge = type_traits::bool_constant<!LessThan<T, Head>::value>;

	using lesser = typename sort<filter_t<C<Ts...>, bind_lt>, LessThan>::type;
	using greater = typename sort<filter_t<C<Ts...>, bind_ge>, LessThan>::type;

	using type = append_t<lesser, push_front_t<greater, Head>>;
};

/**
 * Sort a sequence Seq, LessThan is used to order elements
 */
template<typename Seq, template<typename...> class LessThan>
using sort_t = typename sort<Seq, LessThan>::type;

}} // namespace mbed::meta

#endif /* MBED_META_SORT_H_ */
