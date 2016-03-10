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

#include <core-util/type_traits/add_cv.hpp>
#include <core-util/type_traits/is_same.hpp>

using namespace mbed::type_traits;

// test on value (integer in this case)
static_assert(is_same<const int, add_const_t<int>>::value, "add_const should transform int int const int");
static_assert(is_same<const volatile int, add_const_t<volatile int>>::value, "add_const transfom volatile int into const volatile int");
static_assert(is_same<const int, add_const_t<const int>>::value, "add_const should let const int unchanged");
static_assert(is_same<const volatile int, add_const_t<const volatile int>>::value, "add_const should let const volatile int unchanged");

// test on references to something types
// since references cannot be const (unlike the thing they reference),
// add_const type traits should not have any effect on a type which is a reference
static_assert(is_same<int&, add_const<int&>::type>::value, "add_const should let rvalue reference to types unchanged");
static_assert(is_same<int&&, add_const_t<int&&>>::value, "add_const should let lvalue reference to types unchanged");
static_assert(is_same<const int&, add_const<const int&>::type>::value, "add_const should let rvalue reference to const types unchanged");
static_assert(is_same<const int&&, add_const_t<const int&&>>::value, "add_const should let lvalue reference to const types unchanged");
static_assert(is_same<volatile int&, add_const<volatile int&>::type>::value, "add_const should let rvalue reference to volatile types unchanged");
static_assert(is_same<volatile int&&, add_const_t<volatile int&&>>::value, "add_const should let lvalue reference to volatile types unchanged");
static_assert(is_same<const volatile int&, add_const<const volatile int&>::type>::value, "add_const should let rvalue reference to const volatile types unchanged");
static_assert(is_same<const volatile int&&, add_const_t<const volatile int&&>>::value, "add_const should let lvalue reference to const volatile types unchanged");

// tests on pointers
static_assert(is_same<int* const, add_const_t<int*>>::value, "add_const should make pointer to int const");
static_assert(is_same<volatile int* const, add_const_t<volatile int*>>::value, "add_const should make pointer to volatile int const");
static_assert(is_same<const volatile int* const, add_const_t<const volatile int*>>::value, "add_const should make pointer to const volatile int const");
static_assert(is_same<int* const, add_const_t<int* const>>::value, "add_const should let const pointer to int unchanged");
static_assert(is_same<volatile int* const, add_const_t<volatile int* const>>::value, "add_const should let const pointer to volatile int unchanged");
static_assert(is_same<const volatile int* const, add_const_t<const volatile int* const>>::value, "add_const should let const pointer to const volatile int unchanged");
