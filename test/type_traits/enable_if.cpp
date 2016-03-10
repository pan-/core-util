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

#include <core-util/type_traits/enable_if.hpp>
#include <core-util/type_traits/is_same.hpp>

using namespace mbed::type_traits;

struct dummy_struct {};

// apply enable to function return type
template<typename T>
enable_if_t<is_same<int, T>::value, int&> function_return_tester();
template<typename T>
enable_if_t<is_same<dummy_struct, T>::value, dummy_struct&> function_return_tester();

// apply enable to function argument type
template<typename T>
int& function_argument_tester(enable_if_t<is_same<int, T>::value>* = nullptr);
template<typename T>
dummy_struct& function_argument_tester(enable_if_t<is_same<dummy_struct, T>::value>* = nullptr);


// apply enable if as tag dispatching
template<typename T, typename select = void>
struct template_class_tester {
    using type = bool;
};
template<typename T>
struct template_class_tester<T, enable_if_t<is_same<int, T>::value>> {
    using type = int&;
};
template<typename T>
struct template_class_tester<T, enable_if_t<is_same<dummy_struct, T>::value>> {
    using type = dummy_struct&;
};

template<typename T>
using template_class_tester_t = typename template_class_tester<T>::type;


static_assert(is_same<int&, decltype(function_return_tester<int>())>::value, "enable_if should work for function return");
static_assert(is_same<dummy_struct&, decltype(function_return_tester<dummy_struct>())>::value, "enable_if should work for function return");

static_assert(is_same<int&, decltype(function_argument_tester<int>())>::value, "enable_if should work for function argument");
static_assert(is_same<dummy_struct&, decltype(function_argument_tester<dummy_struct>())>::value, "enable_if should work for function argument");

static_assert(is_same<int&, template_class_tester_t<int>>::value, "enable_if should work for template class");
static_assert(is_same<dummy_struct&, template_class_tester_t<dummy_struct>>::value, "enable_if should work for template class");
static_assert(is_same<bool, template_class_tester_t<float>>::value, "enable_if should work for template class");
