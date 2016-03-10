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

#ifndef MBED_TYPE_TRAITS_ENABLE_IF_H_
#define MBED_TYPE_TRAITS_ENABLE_IF_H_

namespace mbed { namespace type_traits {

/**
 * Help to select a particular template function or a particular (possibly
 * partial) specialization of a template class.
 *
 * If B is equal to true, then a member "type" is available and it is equal to
 * T.
 */
template<bool B, typename T = void>
struct enable_if;

template<typename T>
struct enable_if<true, T> {
    using type = T;
};

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

}} // mbed::type_traits

#endif /* MBED_TYPE_TRAITS_ENABLE_IF_H_ */
