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

#ifndef MBED_TYPE_TRAITS_BOOL_CONSTANT_H_
#define MBED_TYPE_TRAITS_BOOL_CONSTANT_H_

#include "integral_constant.hpp"

namespace mbed { namespace type_traits {

/**
 * Wrap a boolean static constant of type bool
 * @tparam the static boolean value
 */
template<bool V>
using bool_constant = integral_constant<bool, V>;

/// Type representation of the boolean constant true
using true_type = bool_constant<true>;

/// Type representation of the boolean constant false
using false_type = bool_constant<false>;

}} // namespace mbed::type_traits

#endif /* MBED_TYPE_TRAITS_BOOL_CONSTANT_H_ */
