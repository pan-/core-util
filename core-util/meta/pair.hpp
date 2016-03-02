/*
 * pair.hpp
 *
 *  Created on: 26 Feb 2016
 *      Author: vincou01
 */

#ifndef META_PAIR_HPP_
#define META_PAIR_HPP_

namespace mbed { namespace meta {

template<typename FirstType, typename SecondType>
struct pair {
    using first_type = FirstType;
    using second_type = SecondType;
};

}} // namespace mbed::meta

#endif /* META_PAIR_HPP_ */
