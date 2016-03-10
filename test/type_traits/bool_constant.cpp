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

#include <core-util/type_traits/bool_constant.hpp>
#include <core-util/type_traits/is_same.hpp>

using namespace mbed::type_traits;

static_assert(is_same<true_type, bool_constant<true>>::value, "true_type should be equal to bool_constant<true>");
static_assert(is_same<true_type, integral_constant<bool, true>>::value, "true_type should be equal to integral_constant<bool, true>");
static_assert(is_same<true_type::value_type, bool>::value, "true_type::value_type should be equal to bool");
static_assert(true_type::value == true, "true_type::value should be equal to true");

static_assert(is_same<false_type, bool_constant<false>>::value, "false_type should be equal to bool_constant<false>");
static_assert(is_same<false_type, integral_constant<bool, false>>::value, "false_type should be equal to integral_constant<bool, false>");
static_assert(is_same<false_type::value_type, bool>::value, "false_type::value_type should be equal to bool");
static_assert(false_type::value == false, "false_type::value should be equal to false");

static_assert(is_same<bool_constant<0>, false_type>::value, "bool_constant<0> should generate false_type");
static_assert(is_same<bool_constant<1>, true_type>::value, "bool_constant<1> should generate true_type");
