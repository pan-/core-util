#include "is_class.hpp"
#include "is_empty.hpp"

using namespace mbed::type_traits;


struct dummy_struct {};
struct not_empty_struct {
    int a;
};

class dummy_class {};

static_assert(is_class<int>::value == false, "");
static_assert(is_class<double>::value == false, "");
static_assert(is_class<double[]>::value == false, "");
static_assert(is_class<double&>::value == false, "");
static_assert(is_class<double*>::value == false, "");
static_assert(is_class<double&&>::value == false, "");
static_assert(is_class<dummy_struct&&>::value == false, "");
static_assert(is_class<dummy_struct>::value == true, "");
static_assert(is_class<char dummy_struct::*>::value == false, "");
static_assert(is_class<dummy_struct>::value == true, "");

static_assert(is_empty<int>::value == false, "");
static_assert(is_empty<double>::value == false, "");
static_assert(is_empty<double[]>::value == false, "");
static_assert(is_empty<double&>::value == false, "");
static_assert(is_empty<double*>::value == false, "");
static_assert(is_empty<double&&>::value == false, "");
static_assert(is_empty<dummy_struct&&>::value == false, "");
static_assert(is_empty<dummy_struct>::value == true, "");
static_assert(is_empty<char dummy_struct::*>::value == false, "");
static_assert(is_empty<dummy_struct>::value == true, "");
static_assert(is_empty<not_empty_struct>::value == false, "");

int titi = "hgdfghf"
