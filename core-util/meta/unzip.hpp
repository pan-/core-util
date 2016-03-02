/*
 * unzip.hpp
 *
 *  Created on: 26 Feb 2016
 *      Author: vincou01
 */

#ifndef META_UNZIP_HPP_
#define META_UNZIP_HPP_

#include "pair.hpp"
#include "sequence.hpp"
#include "push_front.hpp"

namespace mbed { namespace meta {

namespace detail {

template<typename... Ts>
struct unzip_impl;

template<>
struct unzip_impl<> : public pair<sequence<>, sequence<>>{ };

template<typename T, typename U, typename... Ts>
struct unzip_impl<pair<T, U>, Ts...> :
    public pair<
        push_front_t<typename unzip_impl<Ts...>::first_type, T>,
        push_front_t<typename unzip_impl<Ts...>::second_type, U>
    >   {
};

}

template<typename T>
struct unzip;

template<typename... Ts>
struct unzip<sequence<Ts...>>  {
    using type = pair<
        typename detail::unzip_impl<Ts...>::first_type,
        typename detail::unzip_impl<Ts...>::second_type
    >;
};

template<typename T>
using unzip_t = typename unzip<T>::type;

}} // namespace mbed::meta


#endif /* META_UNZIP_HPP_ */
