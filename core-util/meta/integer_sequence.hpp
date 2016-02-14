#ifndef MBED_META_INTEGER_SEQUENCE_H_
#define MBED_META_INTEGER_SEQUENCE_H_

#include <cstdint>

namespace mbed { namespace meta {

/// model a sequence of integral constants
/// @param T type of constants in sequence
/// @param ...Ints sequence of integers
template<typename T, T... Ints>
struct integer_sequence {

    /// reference to this type
    using type = integer_sequence;

    /// type of constants in the sequence
    using value_type = T;

    /// number of integers in the sequence
    static constexpr std::size_t size() {
        return sizeof...(Ints);
    }
};

/// helper for sequence of indexes
template<std::size_t... Indices>
using index_sequence = integer_sequence<std::size_t, Indices...>;

}} // mbed::meta

#endif /* MBED_META_INTEGER_SEQUENCE_H_ */
