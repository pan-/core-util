#ifndef MBED_META_FILTER_H_
#define MBED_META_FILTER_H_

#include "type_traits/bool_constant.hpp"
#include "type_traits/enable_if.hpp"
#include "push_front.hpp"

namespace mbed { namespace meta {

template<typename Seq, template<typename> class Pred, typename = void>
struct filter;

template<
    template<typename...> class Cont,
    template<typename> class Pred,
    typename Dummy
>
struct filter<Cont<>, Pred, Dummy> {
    using type = Cont<>;
};

template<
    template<typename...> class Cont, typename T1, typename... Ts,
    template<typename> class Pred
>
struct filter<
    Cont<T1, Ts...>,
    Pred,
    type_traits::enable_if_t<Pred<T1>::value>
> {
    using type = push_front_t<
        typename filter<Cont<Ts...>, Pred>::type,
        T1
    >;
};

template<
    template<typename...> class Cont, typename T1, typename... Ts,
    template<typename> class Pred
>
struct filter<
    Cont<T1, Ts...>,
    Pred,
    type_traits::enable_if_t<Pred<T1>::value == false>
> {
    using type = typename filter<Cont<Ts...>, Pred>::type;
};

/**
 * Filter a sequence Seq with a predicate Pred.
 * Return a new sequence containing all elements of Seq which validate: Pred<E> == true_type
 */
template<typename Seq, template<typename> class Pred>
using filter_t = typename filter<Seq, Pred>::type;

}} // namespace mbed::meta

#endif /* MBED_META_FILTER_H_ */
