#ifndef MBED_META_TYPE_TRAITS_REMOVE_REFERENCE_H_
#define MBED_META_TYPE_TRAITS_REMOVE_REFERENCE_H_

namespace mbed { namespace type_traits {

/// Remove reference type from T
template<typename T>
struct remove_reference {
    using type = T;
};

/// specialization of remove_reference for T&
template<typename T>
struct remove_reference<T&> {
    using type = T;
};

/// specialization of remove_reference for T&&
template<typename T>
struct remove_reference<T&&> {
    using type = T;
};

/// direct application of remove_reference
template<typename T>
using remove_reference_t = typename remove_reference<T>::type;

}} // namespace mbed::type_traits

#endif /* MBED_META_TYPE_TRAITS_REMOVE_REFERENCE_H_ */
