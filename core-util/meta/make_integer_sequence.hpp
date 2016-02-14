#ifndef MBED_META_MAKE_INTEGER_SEQUENCE__H_
#define MBED_META_MAKE_INTEGER_SEQUENCE__H_

#include <cstdint>

#include "integer_sequence.hpp"
#include "enable_if.hpp"

namespace mbed { namespace meta {

namespace detail {

template<typename T, typename HalfSeq, T N, bool odd = N % 2>
struct double_seq;

template<typename T, T... Ts, T N>
struct double_seq<T, integer_sequence<T, Ts...>, N, true> {
    using type = integer_sequence<T, Ts..., ((N / 2) + Ts) ..., N - 1>;
};

template<typename T, T... Ts, T N>
struct double_seq<T, integer_sequence<T, Ts...>, N, false> {
    using type = integer_sequence<T, Ts..., ((N / 2) + Ts) ...>;
};

/// @note inherithing from double_seq can speedup the process
template<typename T, T N, typename = void>
struct make_integer_sequence_impl {
    // generate the first half of the sequence
    using half_sequence = typename make_integer_sequence_impl<T, N / 2>::type;

    // generate the whole sequence from the first half
    using type = typename  double_seq<T, half_sequence, N>::type;
};

template<typename T, T N>
struct make_integer_sequence_impl<T, N, enable_if_t<N == 0>> {
    using type = integer_sequence<T>;
};

template<typename T, T N>
struct make_integer_sequence_impl<T, N, enable_if_t<N == 1>> {
    using type = integer_sequence<T, 0>;
};

}

/// create a sequence of N integers of type T
/// @param T the type of integer used
/// @param N the number of integer in the sequence
/// @return integer_sequence<T, 0, 1, ..., N - 1>
template<typename T, T N>
using make_integer_sequence = typename detail::make_integer_sequence_impl<T, N>::type;

// create a sequence of Indices [0..N[
template<std::size_t N>
using make_index_sequence = make_integer_sequence<std::size_t, N>;

/// create an integer sequence of size_t of all indices of a parameter pack
template<typename... T>
using index_sequence_for = make_index_sequence<sizeof...(T)>;

}} // namespace mbed::meta

#endif /* MBED_META_MAKE_INTEGER_SEQUENCE__H_ */
