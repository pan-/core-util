#ifndef MBED_META_APPEND_H_
#define MBED_META_APPEND_H_

namespace mbed { namespace meta {

template<typename L, typename R>
struct append;

template<
    template<typename...> class LeftContainer, typename... LeftTs,
    template<typename...> class RightContainer, typename... RightTs
>
struct append<LeftContainer<LeftTs...>, RightContainer<RightTs...>> {
    using type = LeftContainer<LeftTs..., RightTs...>;
};

template<typename L, typename R>
using append_t = typename append<L, R>::type;

}} // namespace mbed::meta

#endif /* MBED_META_APPEND_H_ */
