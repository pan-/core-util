/*
 * box_integer_sequence.hpp
 *
 *  Created on: 26 Feb 2016
 *      Author: vincou01
 */

#ifndef META_BOX_INTEGER_SEQUENCE_HPP_
#define META_BOX_INTEGER_SEQUENCE_HPP_

#include <cstdint>
#include "box.hpp"
#include "sequence.hpp"
#include "integer_sequence.hpp"

namespace mbed { namespace meta {

template<typename T>
struct box_integer_sequence;

template<typename T, T... values>
struct box_integer_sequence<integer_sequence<T, values...>> {
    using type = sequence<box<T, values>...>;
    using value_type = T;

    /// number of values in the sequence
    static constexpr std::size_t size() {
        return sizeof...(values);
    }
};

template<typename T>
using box_integer_sequence_t = typename box_integer_sequence<T>::type;

}} // namespace mbed::meta


#endif /* META_BOX_INTEGER_SEQUENCE_HPP_ */
