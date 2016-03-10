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

#ifndef MBED_CORE_UTIL_TYPE_TRAITS_ADD_CV_HPP_
#define MBED_CORE_UTIL_TYPE_TRAITS_ADD_CV_HPP_

namespace mbed { namespace type_traits {

/**
 * Add const and volatile qualifiers to T.
 * @tparam T the type to transform
 */
template<class T>
struct add_cv {
    /**
     * result of the type trait: const volatile T
     */
    using type = const volatile T;
};

/**
 * Alias template for add_cv.
 * Equivalent to the expression typename add_cv<T>::type
 */
template<typename T>
using add_cv_t = typename add_cv<T>::type;

/**
 * Add const qualifiers to T.
 * @tparam T the type to transform
 */
template<class T>
struct add_const {
    /**
     * result of the type trait: const T
     */
    using type = const T;
};

/**
 * Alias template for add_const.
 * Equivalent to the expression typename add_const<T>::type
 */
template<typename T>
using add_const_t = typename add_const<T>::type;

/**
 * Add volatile qualifiers to T.
 * @tparam T the type to transform
 */
template<class T>
struct add_volatile {
    /**
     * result of the type trait: volatile T
     */
    using type = volatile T;
};

/**
 * Alias template for add_volatile.
 * Equivalent to the expression typename add_volatile<T>::type
 */
template<typename T>
using add_volatile_t = typename add_volatile<T>::type;

}} // namespace mbed::type_traits

#endif /* MBED_CORE_UTIL_TYPE_TRAITS_ADD_CV_HPP_ */
