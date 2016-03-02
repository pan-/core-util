/*
 * box_value_sequence.hpp
 *
 *  Created on: 26 Feb 2016
 *      Author: vincou01
 */

#ifndef META_BOX_VALUE_SEQUENCE_HPP_
#define META_BOX_VALUE_SEQUENCE_HPP_

#include <cstdint>
#include "box.hpp"
#include "sequence.hpp"

namespace mbed { namespace meta {

template<typename T, T... values>
struct box_value_sequence {
    using type = sequence<box<T, values>...>;
    using value_type = T;

    /// number of values in the sequence
    static constexpr std::size_t size() {
        return sizeof...(values);
    }
};

template<typename T, T... values>
using box_value_sequence_t = typename box_value_sequence<T, values...>::type;


}} // namespace mbed::meta



#endif /* META_BOX_VALUE_SEQUENCE_HPP_ */
