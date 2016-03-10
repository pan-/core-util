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

#include <core-util/type_traits/is_same.hpp>
#include <core-util/type_traits/identity.hpp>

using namespace mbed::type_traits;

struct dummy_struct {};

// plain type
static_assert(is_same<dummy_struct, identity_t<dummy_struct>>::value, "identity should work for value type");
static_assert(is_same<const dummy_struct, identity_t<const dummy_struct>>::value, "identity should work for const value type");
static_assert(is_same<volatile dummy_struct, identity_t<volatile dummy_struct>>::value, "identity should work for volatile value type");
static_assert(is_same<const volatile dummy_struct, identity_t<const volatile dummy_struct>>::value, "identity should work for const volatile value type");

// references
static_assert(is_same<dummy_struct&, identity_t<dummy_struct&>>::value, "identity should work for reference type");
static_assert(is_same<const dummy_struct&, identity_t<const dummy_struct&>>::value, "identity should work for reference to const type");
static_assert(is_same<volatile dummy_struct&, identity_t<volatile dummy_struct&>>::value, "identity should work for reference to volatile type");
static_assert(is_same<const volatile dummy_struct&, identity_t<const volatile dummy_struct&>>::value, "identity should work for reference to const volatile type");

// pointer
static_assert(is_same<dummy_struct*, identity_t<dummy_struct*>>::value, "identity should work for pointer type");
static_assert(is_same<const dummy_struct*, identity_t<const dummy_struct*>>::value, "identity should work for pointer to const type");
static_assert(is_same<volatile dummy_struct*, identity_t<volatile dummy_struct*>>::value, "identity should work for pointer to volatile type");
static_assert(is_same<const volatile dummy_struct*, identity_t<const volatile dummy_struct*>>::value, "identity should work for pointer to const volatile type");

// const pointer
static_assert(is_same<dummy_struct* const, identity_t<dummy_struct* const>>::value, "identity should work for const pointer type");
static_assert(is_same<const dummy_struct* const, identity_t<const dummy_struct* const>>::value, "identity should work for const pointer to const type");
static_assert(is_same<volatile dummy_struct* const, identity_t<volatile dummy_struct* const>>::value, "identity should work for const pointer to volatile type");
static_assert(is_same<const volatile dummy_struct* const, identity_t<const volatile dummy_struct* const>>::value, "identity should work for const pointer to const volatile type");

// volatile pointer
static_assert(is_same<dummy_struct* volatile, identity_t<dummy_struct* volatile>>::value, "identity should work for volatile pointer type");
static_assert(is_same<const dummy_struct* volatile, identity_t<const dummy_struct* volatile>>::value, "identity should work for volatile pointer to const type");
static_assert(is_same<volatile dummy_struct* volatile, identity_t<volatile dummy_struct* volatile>>::value, "identity should work for volatile pointer to volatile type");
static_assert(is_same<const volatile dummy_struct* volatile, identity_t<const volatile dummy_struct* volatile>>::value, "identity should work for volatile pointer to const volatile type");

// const volatile pointer
static_assert(is_same<dummy_struct* const volatile, identity_t<dummy_struct* const volatile>>::value, "identity should work for const volatile pointer type");
static_assert(is_same<const dummy_struct* const volatile, identity_t<const dummy_struct* const volatile>>::value, "identity should work for const volatile pointer to const type");
static_assert(is_same<volatile dummy_struct* const volatile, identity_t<volatile dummy_struct* const volatile>>::value, "identity should work for const volatile pointer to volatile type");
static_assert(is_same<const volatile dummy_struct* const volatile, identity_t<const volatile dummy_struct* const volatile>>::value, "identity should work for const volatile pointer to const volatile type");

// pointer to pointer
static_assert(is_same<dummy_struct**, identity_t<dummy_struct**>>::value, "identity should work for pointer to pointer type");
static_assert(is_same<const dummy_struct**, identity_t<const dummy_struct**>>::value, "identity should work for pointer to pointer to const type");
static_assert(is_same<volatile dummy_struct**, identity_t<volatile dummy_struct**>>::value, "identity should work for pointer to pointer to volatile type");
static_assert(is_same<const volatile dummy_struct**, identity_t<const volatile dummy_struct**>>::value, "identity should work for pointer to pointer to const volatile type");

// const pointer to pointer
static_assert(is_same<dummy_struct** const, identity_t<dummy_struct** const>>::value, "identity should work for const pointer to pointer type");
static_assert(is_same<const dummy_struct** const, identity_t<const dummy_struct** const>>::value, "identity should work for const pointer to pointer to const type");
static_assert(is_same<volatile dummy_struct** const, identity_t<volatile dummy_struct** const>>::value, "identity should work for const pointer to pointer to volatile type");
static_assert(is_same<const volatile dummy_struct** const, identity_t<const volatile dummy_struct** const>>::value, "identity should work for const pointer to pointer to const volatile type");

// volatile pointer to pointer
static_assert(is_same<dummy_struct** volatile, identity_t<dummy_struct** volatile>>::value, "identity should work for volatile pointer to pointer type");
static_assert(is_same<const dummy_struct** volatile, identity_t<const dummy_struct** volatile>>::value, "identity should work for volatile pointer to pointer to const type");
static_assert(is_same<volatile dummy_struct** volatile, identity_t<volatile dummy_struct** volatile>>::value, "identity should work for volatile pointer to pointer to volatile type");
static_assert(is_same<const volatile dummy_struct** volatile, identity_t<const volatile dummy_struct** volatile>>::value, "identity should work for volatile pointer to pointer to const volatile type");

// const volatile pointer to pointer
static_assert(is_same<dummy_struct** const volatile, identity_t<dummy_struct** const volatile>>::value, "identity should work for const volatile pointer to pointer type");
static_assert(is_same<const dummy_struct** const volatile, identity_t<const dummy_struct** const volatile>>::value, "identity should work for const volatile pointer to pointer to const type");
static_assert(is_same<volatile dummy_struct** const volatile, identity_t<volatile dummy_struct** const volatile>>::value, "identity should work for const volatile pointer to pointer to volatile type");
static_assert(is_same<const volatile dummy_struct** const volatile, identity_t<const volatile dummy_struct** const volatile>>::value, "identity should work for const volatile pointer to pointer to const volatile type");
