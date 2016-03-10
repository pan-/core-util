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

#ifndef MBED_TYPE_TRAITS_IDENTITY_H_
#define MBED_TYPE_TRAITS_IDENTITY_H_

namespace mbed { namespace type_traits {

/**
 * Simple type trait which return the T in input, as is.
 * The purpose of this trait is remove limitation of decltype from armcc.
 * For instance, armcc does not allow:
 * \code
 *  class X : decltype(Y) {};.
 * \endcode
 * but the following statement is authorized:
 * \code
 *  class X : identity_t<decltype(Y)> {};.
 * \endcode
 */
template<typename T>
struct identity {
    /**
     * result of the trait, should be equal to T.
     */
    using type = T;
};

/**
 * shorthand for typename identity<T>::type
 */
template<typename T>
using identity_t = typename identity<T>::type;

}} // namespace mbed::type_traits

#endif /* MBED_TYPE_TRAITS_IDENTITY_H_ */
