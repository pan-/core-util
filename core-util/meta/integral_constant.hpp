#ifndef MBED_META_INTEGRAL_CONSTANT_H_
#define MBED_META_INTEGRAL_CONSTANT_H_

namespace mbed {
namespace meta {

/// Wraps a static constant 'V' of specified type 'T'.
/// @tparam T type of the static constant wrapped
/// @tparam V value wrapped
template<typename T, T V>
struct integral_constant {
    /// Type wrapped.
    using value_type = T;

    /// This type.
    using type = integral_constant;

    /// Static constant of type T with value V
    static constexpr value_type value = V;

    /// Conversion operator to T, it will always return V
    constexpr operator value_type() const noexcept {
        return value;
    }

    /// Nulary Function operator, it will always return V
    constexpr value_type operator()() const noexcept {
        return value;
    }
};

} // namespace meta
} // namespace mbed

#endif /* MBED_META_INTEGRAL_CONSTANT_H_ */
