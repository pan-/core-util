/*
 * Copyright (c) 2015-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_TYPE_TRAITS_INTEGRAL_CONSTANT_H_
#define MBED_TYPE_TRAITS_INTEGRAL_CONSTANT_H_

namespace mbed { namespace type_traits {

/**
 * Wraps a static constant 'V' of specified type 'T' inside a type.
 * @tparam T type of the static constant wrapped
 * @tparam V value wrapped
 */
template<typename T, T V>
struct integral_constant {
    /**
     * type of the value wrapped
     */
    using value_type = T;

    /**
     * Type of this type
     */
    using type = integral_constant;

    /**
     * static constant of the value wrapped, always equal to V
     */
    static constexpr value_type value = V;

    /**
     * constexpr conversion function to T.
     * @return V
     */
    constexpr operator value_type() const noexcept {
        return value;
    }

    /**
     * Nulary Function operator, it will always return V
     * @return V
     */
    constexpr value_type operator()() const noexcept {
        return value;
    }
};

}} // namespace mbed::type_traits

#endif /* MBED_TYPE_TRAITS_INTEGRAL_CONSTANT_H_ */
