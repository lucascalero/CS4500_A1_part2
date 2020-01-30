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

void test_constructor_equal_arrays() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Array* a = new Array(3);
    Array* b = new Array();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->push_back(o);
    b->push_back(q);
    b->push_back(p);
    
    s.t_true(a->equals(b));
    s.OK("Two arrays constructd with different constructors.");
}

void test_clone_returns_same_hash() {
    Object* o = new Object();
    Array* a = new Array();
    a->push_back(o);
    Array* b = a->clone();
    s.t_true(a->equals(b));
    s.OK("Clone returns new object with same hash.");
}


void test_clone_not_same_after_adding_new_item() {
    Object* o = new Object();
    Object* p = new Object();
    Array* a = new Array();
    a->push_back(o);
    Array* b = a->clone();
    a->push_back(p);

    s.t_false(a->equals(b));
    s.OK("Clone has different hash than original after adding item to orig.");
}


void test_clone_not_same_after_adding_new_item() {
    Object* o = new Object();
    Object* p = new Object();
    Array* a = new Array();
    a->push_back(o);
    Array* b = a->clone();
    a->push_back(p);
    s.t_false(a->equals(b));
    s.OK("Clone has different hash than original after adding item to orig.");
}


void test_add_all_works() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Array* a = new Array(3);
    Array* b = new Array();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->add_all(0,a);
    
    s.t_true(a->equals(b));
    s.OK("Test add all works");
}

void test_index_of_object_in_array() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Array* a = new Array(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    s.t_true(a->index_of(o) == 0);
    s.t_true(a->index_of(q) == 1);
    s.t_true(a->index_of(p) == 2);
    s.OK("index_of when objects exist in array");
}


void test_index_of_object_not_in_array() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Object* n = new Object();
    Array* a = new Array(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    s.t_true(a->index_of(n) == 3);
    s.OK("index_of when objects dont exist in array");
}

void test_size_empty() {
    Array* a = new Array();
    s.t_true(a->size() == 0);
    s.OK("Size is empty correctly");
}

void test_size_not_empty() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Array* a = new Array(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    s.t_true(a->size() == 3);
    s.OK("size not empty correct");
}

void test_get_returns_same_object() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Array* a = new Array(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    s.t_true(a->get(0)->equals(o));
    s.t_false(a->get(1)->equals(o));
    s.t_true(a->get(1)->equals(q));
    s.t_false(a->get(0)->equals(q));
    s.t_true(a->get(2)->equals(p));

    s.OK("Get returns correct objects");
}

void test_remove_correct_object() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Array* a = new Array(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    Object* removed = a->remove(1);

    s.t_true(removed->equals(q));
    s.t_false(removed->equals(p));
    s.OK("Removes the correct object at the correct index");
}

void test_remove_leaves_blank_pointer() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Array* a = new Array(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    Object* removed = a->remove(1);

    s.t_true(a->get(1) == nullptr);
    s.t_false(removed->equals(p));
    s.OK("Removes the correct object at the correct index");
}




