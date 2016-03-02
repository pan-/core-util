#ifndef MBED_TUPLE_H_
#define MBED_TUPLE_H_

#include <cstdint>

#include "detail/tuple_impl.hpp"
#include "tuple_element.hpp"
#include "meta/sequence.hpp"
#include "meta/integer_sequence.hpp"
#include "meta/make_integer_sequence.hpp"
#include "utility/forward.hpp"
#include "type_traits/bool_constant.hpp"

namespace mbed {

template<typename... Ts>
class tuple : public detail::tuple_impl<Ts...> {

    using impl_type = detail::tuple_impl<Ts...>;

public:
    constexpr tuple() { }

    template<typename... Us>
    constexpr tuple(Us&&... values) : impl_type(utility::forward<Us>(values)...) { }

    template<std::size_t Index>
    tuple_element_t<Index, tuple<Ts...>>& get() &  {
        return impl_type::template get<Index, meta::at_t<meta::sequence<Ts...>, Index>>();
    }

    template<std::size_t Index>
    tuple_element_t<Index, tuple<Ts...>>&& get() && {
        return impl_type::template get<Index, meta::at_t<meta::sequence<Ts...>, Index>>();
    }

    template<std::size_t Index>
    constexpr const tuple_element_t<Index, tuple<Ts...>>& get() const& {
        return impl_type::template get<Index, meta::at_t<meta::sequence<Ts...>, Index>>();
    }

    template<std::size_t Index>
    constexpr const tuple_element_t<Index, tuple<Ts...>>&& get() const && {
        return static_cast<const impl_type&&>(*this).template get<Index, meta::at_t<meta::sequence<Ts...>, Index>>();
    }
};


template<typename... Ts>
constexpr tuple<Ts&&...> forward_as_tuple(Ts&&... args) {
    return tuple<Ts&&...>(utility::forward<Ts>(args)...);
}

} // namespace mbed


#endif /* MBED_TUPLE_H_ */
