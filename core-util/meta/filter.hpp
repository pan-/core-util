#ifndef MBED_META_APPEND_H_
#define MBED_META_APPEND_H_

#include "type_traits/bool_constant.hpp"
#include "type_traits/enable_if.hpp"
#include "push_front.hpp"

namespace mbed { namespace meta {

template<template<typename> class Pred, typename Seq, typename = void>
struct filter;

template<
    template<typename> class Pred,
    template<typename...> class Cont,
    typename Dummy
>
struct filter<Pred, Cont<>, Dummy> {
	using type = Cont<>;
};

template<
    template<typename> class Pred,
    template<typename...> class Cont, typename T1, typename... Ts
>
struct filter<
    Pred,
    Cont<T1, Ts...>,
    type_traits::enable_if_t<Pred<T1>::value>
> {
	using type = push_front_t<
        typename filter<Pred, Cont<Ts...>>::type,
        T1
    >;
};

template<
    template<typename> class Pred,
    template<typename...> class Cont, typename T1, typename... Ts
>
struct filter<
    Pred,
    Cont<T1, Ts...>,
    type_traits::enable_if_t<Pred<T1>::value == false>
> {
	using type = typename filter<Pred, Cont<Ts...>>::type;
};

/**
 * Filter a sequence Seq with a predicate Pred.
 * Return a new sequence containing all elements of Seq which validate: Pred<E> == true_type
 */
template<template<typename> class Pred, typename Seq>
using filter_t = typename filter<Pred, Seq>::type;

}} // namespace mbed::meta

#endif /* MBED_META_APPEND_H_ */
