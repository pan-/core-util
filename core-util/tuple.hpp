#ifndef MBED_TUPLE_H_
#define MBED_TUPLE_H_

#include <cstdint>

#include "detail/tuple_impl.hpp"
#include "meta/sequence.hpp"
#include "meta/integer_sequence.hpp"
#include "meta/make_integer_sequence.hpp"
#include "utility/forward.hpp"

namespace mbed {

template<std::size_t index, typename T>
struct indexed_element {
    static constexpr std::size_t index_value = index;
    using element_type = T;
};


template<typename Indices, typename... Ts>
struct make_indexed_sequence_impl;

template<std::size_t... Indices, typename... Ts>
struct make_indexed_sequence_impl<meta::index_sequence<Indices...>, Ts...> {
    using type = meta::sequence<indexed_element<Indices, Ts>...>;
};



// return a list of indexed elements
template<typename... Ts>
struct make_indexed_sequence {
    using type = typename make_indexed_sequence_impl<meta::index_sequence_for<Ts...>, Ts...>::type;
};

template<typename... Ts>
using make_indexed_sequence_t = typename make_indexed_sequence<Ts...>::type;



template<typename... Ts>
class tuple : public detail::tuple_impl<meta::index_sequence_for<Ts...>, Ts...> {

    using impl_type = detail::tuple_impl<meta::index_sequence_for<Ts...>, Ts...>;

public:
    constexpr tuple() { }

    template<typename... Us>
    constexpr tuple(Us&&... values) : impl_type(utility::forward<Us>(values)...) { }

};




template<typename... Ts>
constexpr tuple<Ts&&...> forward_as_tuple(Ts&&... args) {
    return tuple<Ts&&...>(utility::forward<Ts>(args)...);
}

} // namespace mbed


#endif /* MBED_TUPLE_H_ */
