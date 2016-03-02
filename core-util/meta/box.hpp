/*
 * box.hpp
 *
 *  Created on: 26 Feb 2016
 *      Author: vincou01
 */

#ifndef META_BOX_HPP_
#define META_BOX_HPP_

namespace mbed { namespace meta {

template<typename T, T val>
struct box {
    using type = box;
    using value_type = T;
    static constexpr T value = val;
};

}} // namespace mbed::meta

#endif /* META_BOX_HPP_ */
