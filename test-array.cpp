#include "helper.h"
#include "array.h"
#include "object.h"
#include "string.h"

Sys s = Sys();

void test_empty_array_equals_empty_array() {
    Array* a = new Array();
    Array* b = new Array();
    s.t_true(a->equals(b));
    s.OK("two empty arrays are equal");
}

void test_array_equals() {
    Object* o = new Object();
    Object* p = new Object();
    Array* a = new Array();
    Array* b = new Array();
    a->push_back(o);
    a->push_back(p);
    b->push_back(o);
    b->push_back(p);
    s.t_true(a->equals(b));
    s.OK("two arrays with the same objects have same hash");
}

void test_arrays_are_not_equal() {
    Object* o = new Object();
    Object* p = new Object();
    Array* a = new Array();
    Array* b = new Array();
    a->push_back(o);
    b->push_back(p);
    s.t_false(a->equals(b));
    s.OK("Two different arrays have different hash values.");
}