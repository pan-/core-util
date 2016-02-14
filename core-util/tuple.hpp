#ifndef MBED_TUPLE_H_
#define MBED_TUPLE_H_

#include <cstdint>

#include "detail/tuple_impl.hpp"
#include "meta/sequence.hpp"
#include "meta/make_integer_sequence.hpp"
#include "utility/forward.hpp"

namespace mbed {

template<typename... Ts>
class tuple : public detail::tuple_impl<meta::index_sequence_for<Ts...>, Ts...> {

    using impl_type = detail::tuple_impl<meta::index_sequence_for<Ts...>, Ts...>;

public:
    constexpr tuple() { }

    constexpr tuple(Ts&&... values) : impl_type(utility::forward<Ts>(values)...) { }

};



}


#endif /* MBED_TUPLE_H_ */
