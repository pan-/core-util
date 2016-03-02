#ifndef MBED_META_PUSH_BACK__H_
#define MBED_META_PUSH_BACK__H_

namespace mbed { namespace meta {

namespace detail {

template<typename S, typename... Elements>
struct push_back_impl_;

template<template<class... > class  C, typename... Ts, typename... Elements>
struct push_back_impl_<C<Ts...>, Elements...> {
    using type = C<Ts..., Elements...>;
};

} // namespace detail

/// Append a parameter pack of Elements to a Sequence S
/// @param S a sequence made of a container C and a parameter pack Ts... such as
/// S = C<Ts...>
/// @param ...Elements parameter packs of elements to push back
/// @return a new sequence: C<Ts..., Elements...>
template<typename S, typename... Elements>
using push_back_ = typename detail::push_back_impl_<S, Elements...>::type;

} } // mbed::meta

#endif /* MBED_META_PUSH_BACK__H_ */
