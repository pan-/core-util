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
#include <core-util/type_traits/integral_constant.hpp>
#include <limits>

using namespace mbed::type_traits;

// generic set of tests for integral_constant
template<typename T, T value>
struct integral_constant_tester {

    using constant_t = integral_constant<T, value>;
    static constexpr constant_t constant_v {};
    static_assert(
        is_same<T, typename constant_t::value_type>::value,
        "value_type for integral_constant should be equal to the type passed at instantiation"
    );
    static_assert(
        value == constant_t::value,
        "integral_constant::value should be equal to the value passed during type instantiation"
    );
    static_assert(
        is_same<typename constant_t::type, constant_t>::value,
        "integral_constant::type should be equal to itself"
    );
    static_assert(
        constant_v == value,
        "integral_constant conversion function should yield the constant passed during type instantiation"
    );
    static_assert(
        constant_v() == value,
        "integral_constant nulary function operator should yield the constant passed during type instantiation"
    );
};

#if 0
// tests for bool
template struct integral_constant_tester<bool, false>;
template struct integral_constant_tester<bool, true>;

// tests for integral_constant when T is a numeric type
template<typename T>
struct numeric_constant_tester {
    // regular value
    static constexpr integral_constant_tester<T, std::numeric_limits<T>::min()> min_tester {};
    static constexpr integral_constant_tester<T, std::numeric_limits<T>::max()> max_tester {};
    static constexpr integral_constant_tester<T, std::numeric_limits<T>::max() / 2> half_tester {};
    // const value
    static constexpr integral_constant_tester<const T, std::numeric_limits<T>::min()> const_min_tester {};
    static constexpr integral_constant_tester<const T, std::numeric_limits<T>::max()> const_max_tester {};
    static constexpr integral_constant_tester<const T, std::numeric_limits<T>::max() / 2> const_half_tester {};
};
// tests for numeric constants
template struct numeric_constant_tester<bool>;
template struct numeric_constant_tester<char>;
template struct numeric_constant_tester<signed char>;
template struct numeric_constant_tester<unsigned char>;
template struct numeric_constant_tester<wchar_t>;
template struct numeric_constant_tester<short>;
template struct numeric_constant_tester<unsigned short>;
template struct numeric_constant_tester<int>;
template struct numeric_constant_tester<unsigned int>;
template struct numeric_constant_tester<long>;
template struct numeric_constant_tester<unsigned long>;
template struct numeric_constant_tester<long long>;
template struct numeric_constant_tester<unsigned long long>;

// tests for ptr type
template struct integral_constant_tester<void*, nullptr>;
template struct integral_constant_tester<bool*, nullptr>;
template struct integral_constant_tester<char*, nullptr>;
template struct integral_constant_tester<signed char*, nullptr>;
template struct integral_constant_tester<unsigned char*, nullptr>;
template struct integral_constant_tester<wchar_t*, nullptr>;
template struct integral_constant_tester<short*, nullptr>;
template struct integral_constant_tester<unsigned short*, nullptr>;
template struct integral_constant_tester<int*, nullptr>;
template struct integral_constant_tester<unsigned int*, nullptr>;
template struct integral_constant_tester<long*, nullptr>;
template struct integral_constant_tester<unsigned long*, nullptr>;
template struct integral_constant_tester<long long*, nullptr>;
template struct integral_constant_tester<unsigned long long*, nullptr>;


// test for reference
static constexpr int the_answer = 42;
template<> struct integral_constant_tester<const int&, the_answer>;

// tests for reference to array
static constexpr char array_of_char[4] = { 0, 1, 2, 3};
template<> struct integral_constant_tester<const char (&)[4], array_of_char>;

// test for enum
enum bool_e {
    TRUE_VALUE,
    FALSE_VALUE
};
template<> struct integral_constant_tester<bool_e, TRUE_VALUE>;
template<> struct integral_constant_tester<bool_e, FALSE_VALUE>;

// test for enum class
enum class bool_t {
    TRUE_VALUE,
    FALSE_VALUE
};
template<> struct integral_constant_tester<bool_t, bool_t::TRUE_VALUE>;
template<> struct integral_constant_tester<bool_t, bool_t::FALSE_VALUE>;
#endif
static constexpr int the_answer = 42;
// test for struct
struct dummy_struct {
    constexpr dummy_struct() : value(the_answer) { }

    static void dummy_free_function() { }
    void dummy_member_function() { }
    const void* dummy_member_data = nullptr;
    int value;

};

static constexpr  dummy_struct dummy_instance {};



//template<> struct integral_constant_tester<const dummy_struct&, dummy_instance>;
