#include "helper.h"
#include "array.h"
#include "object.h"
#include "string.h"


Sys s = Sys();

//Array

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
    s.OK("Two different arrays are not equal");
}

void test_array_hash() {
    Object* o = new Object();
    Object* p = new Object();
    Array* a = new Array();
    Array* b = new Array();
    a->push_back(o);
    a->push_back(p);
    b->push_back(o);
    b->push_back(p);
    s.t_true(a->hash() == b->hash());
    s.OK("two arrays with the same objects have same hash");
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


void test_clone_not_same_after_adding_new_item_array() {
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

    Object* ret1 = (Object*)a->get(0);
    Object* ret2 = (Object*)a->get(1);
    Object* ret3 = (Object*)a->get(2);

    s.t_true(ret1->equals(o));
    s.t_false(ret2->equals(o));
    s.t_true(ret2->equals(q));
    s.t_false(ret1->equals(q));
    s.t_true(ret3->equals(p));

    s.OK("Get returns correct objects");
}

void test_clear_correctly_empties_entire_array() {
    Object* o = new Object();
    Object* q = new Object();
    Object* p = new Object();
    Array* a = new Array(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    a->clear();

    s.t_true(a->get(0) == nullptr);
    s.t_true(a->get(1) == nullptr);
    s.t_true(a->get(2) == nullptr);
    s.OK("array is clear");
}


//StrArray

void test_empty_StrArray_equals_empty_StrArray() {
    StrArray* a = new StrArray();
    StrArray* b = new StrArray();
    s.t_true(a->equals(b));
    s.OK("two empty StrArrays are equal");
}

void test_StrArray_equals() {
    String* o = new String("Example 1");
    String* p = new String("Example 2");
    StrArray* a = new StrArray();
    StrArray* b = new StrArray();
    a->push_back(o);
    a->push_back(p);
    b->push_back(o);
    b->push_back(p);
    s.t_true(a->equals(b));
    s.OK("two StrArrays with the same Strings have same hash");
}

void test_StrArrays_are_not_equal() {
    String* o = new String("Example 1");
    String* p = new String("Example 2");
    StrArray* a = new StrArray();
    StrArray* b = new StrArray();
    a->push_back(o);
    b->push_back(p);
    s.t_false(a->equals(b));
    s.OK("Two different StrArrays have different hash values.");
}

void test_constructor_equal_StrArrays() {
    String* o = new String("Example 1");
    String* q = new String("Example 3");
    String* p = new String("Example 2");
    StrArray* a = new StrArray(3);
    StrArray* b = new StrArray();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->push_back(o);
    b->push_back(q);
    b->push_back(p);
    
    s.t_true(a->equals(b));
    s.OK("Two StrArrays constructd with different constructors.");
}

void test_clone_returns_same_hash_str_array() {
    String* o = new String("Example 1");
    StrArray* a = new StrArray();
    a->push_back(o);
    StrArray* b = a->clone();
    s.t_true(a->equals(b));
    s.OK("Clone returns new String with same hash.");
}


void test_clone_not_same_after_adding_new_item_str_array() {
    String* o = new String("Example 1");
    String* p = new String("Example 2");
    StrArray* a = new StrArray();
    a->push_back(o);
    StrArray* b = a->clone();
    a->push_back(p);

    s.t_false(a->equals(b));
    s.OK("Clone has different hash than original after adding item to orig.");
}

void test_add_all_works_str_array() {
    String* o = new String("Example 1");
    String* q = new String("Example 3");
    String* p = new String("Example 2");
    StrArray* a = new StrArray(3);
    StrArray* b = new StrArray();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->add_all(0,a);
    
    s.t_true(a->equals(b));
    s.OK("Test add all works");
}

void test_size_empty_str_array() {
    StrArray* a = new StrArray();
    s.t_true(a->size() == 0);
    s.OK("Size is empty correctly");
}

void test_size_not_empty_str_array() {
    String* o = new String("Example 1");
    String* q = new String("Example 3");
    String* p = new String("Example 2");
    StrArray* a = new StrArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    s.t_true(a->size() == 3);
    s.OK("size not empty correct");
}

void test_get_returns_same_String_str_array() {
    String* o = new String("Example 1");
    String* q = new String("Example 3");
    String* p = new String("Example 2");
    StrArray* a = new StrArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    s.t_true(a->get(0)->equals(o));
    s.t_false(a->get(1)->equals(o));
    s.t_true(a->get(1)->equals(q));
    s.t_false(a->get(0)->equals(q));
    s.t_true(a->get(2)->equals(p));

    s.OK("Get returns correct Strings");
}

void test_clear_correctly_empties_entire_StrArray() {
    String* o = new String("Example 1");
    String* q = new String("Example 3");
    String* p = new String("Example 2");
    StrArray* a = new StrArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    a->clear();

    s.t_true(a->get(0) == nullptr);
    s.t_true(a->get(1) == nullptr);
    s.t_true(a->get(2) == nullptr);
    s.OK("StrArray is clear");
}


// IntArray


void test_empty_IntArray_equals_empty_IntArray() {
    IntArray* a = new IntArray();
    IntArray* b = new IntArray();
    s.t_true(a->equals(b));
    s.OK("two empty IntArrays are equal");
}

void test_IntArray_equals() {
    int i1 = 1;
    int i2 = 2;
    int* o = &i1;
    int* p = &i2;
    IntArray* a = new IntArray();
    IntArray* b = new IntArray();
    a->push_back(o);
    a->push_back(p);
    b->push_back(o);
    b->push_back(p);
    s.t_true(a->equals(b));
    s.OK("two IntArrays with the same ints have same hash");
}

void test_IntArrays_are_not_equal() {
    int i1 = 1;
    int i2 = 2;
    int* o = &i1;
    int* p = &i2;
    IntArray* a = new IntArray();
    IntArray* b = new IntArray();
    a->push_back(o);
    b->push_back(p);
    s.t_false(a->equals(b));
    s.OK("Two different IntArrays have different hash values.");
}

void test_constructor_equal_IntArrays() {
    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    int* o = &i1;
    int* p = &i2;
    int* q = &i3;
    
    IntArray* a = new IntArray(3);
    IntArray* b = new IntArray();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->push_back(o);
    b->push_back(q);
    b->push_back(p);
    
    s.t_true(a->equals(b));
    s.OK("Two IntArrays constructd with different constructors.");
}

void test_clone_returns_same_hash_int_array() {
    int i1 = 1;
    int* o = &i1;
    IntArray* a = new IntArray();
    a->push_back(o);
    IntArray* b = a->clone();
    s.t_true(a->equals(b));
    s.OK("Clone returns new int with same hash.");
}


void test_clone_not_same_after_adding_new_item_int_array() {
    int i1 = 1;
    int i2 = 2;
    int* o = &i1;
    int* p = &i2;
    IntArray* a = new IntArray();
    a->push_back(o);
    IntArray* b = a->clone();
    a->push_back(p);

    s.t_false(a->equals(b));
    s.OK("Clone has different hash than original after adding item to orig.");
}


void test_add_all_works_int_array() {
    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    int* o = &i1;
    int* p = &i2;
    int* q = &i3;
    IntArray* a = new IntArray(3);
    IntArray* b = new IntArray();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->add_all(0,a);
    
    s.t_true(a->equals(b));
    s.OK("Test add all works");
}

void test_size_empty_int_array() {
    IntArray* a = new IntArray();
    s.t_true(a->size() == 0);
    s.OK("Size is empty correctly");
}

void test_size_not_empty_int_array() {
    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    int* o = &i1;
    int* p = &i2;
    int* q = &i3;
    IntArray* a = new IntArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    s.t_true(a->size() == 3);
    s.OK("size not empty correct");
}

void test_get_returns_same_int_array() {
    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    int* o = &i1;
    int* p = &i2;
    int* q = &i3;
    IntArray* a = new IntArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    s.t_true(a->get(0) == o);
    s.t_false(a->get(1) == o);
    s.t_true(a->get(1) == q);
    s.t_false(a->get(0) == q);
    s.t_true(a->get(2) == p);

    s.OK("Get returns correct ints");
}


void test_clear_correctly_empties_entire_IntArray() {
    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    int* o = &i1;
    int* p = &i2;
    int* q = &i3;
    IntArray* a = new IntArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    a->clear();

    s.t_true(a->get(0) == nullptr);
    s.t_true(a->get(1) == nullptr);
    s.t_true(a->get(2) == nullptr);
    s.OK("IntArray is clear");
}


// FloatArray


void test_empty_FloatArray_equals_empty_FloatArray() {
    FloatArray* a = new FloatArray();
    FloatArray* b = new FloatArray();
    s.t_true(a->equals(b));
    s.OK("two empty FloatArrays are equal");
}

void test_FloatArray_equals() {
    float i1 = 1.1;
    float i2 = 2.2;
    float* o = &i1;
    float* p = &i2;
    FloatArray* a = new FloatArray();
    FloatArray* b = new FloatArray();
    a->push_back(o);
    a->push_back(p);
    b->push_back(o);
    b->push_back(p);
    s.t_true(a->equals(b));
    s.OK("two FloatArrays with the same floats have same hash");
}

void test_FloatArrays_are_not_equal() {
    float i1 = 1.1;
    float i2 = 2.2;
    float* o = &i1;
    float* p = &i2;
    FloatArray* a = new FloatArray();
    FloatArray* b = new FloatArray();
    a->push_back(o);
    b->push_back(p);
    s.t_false(a->equals(b));
    s.OK("Two different FloatArrays have different hash values.");
}

void test_constructor_equal_FloatArrays() {
    float i1 = 1.1;
    float i2 = 2.2;
    float i3 = 3.3;
    float* o = &i1;
    float* p = &i2;
    float* q = &i3;
    
    FloatArray* a = new FloatArray(3);
    FloatArray* b = new FloatArray();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->push_back(o);
    b->push_back(q);
    b->push_back(p);
    
    s.t_true(a->equals(b));
    s.OK("Two FloatArrays constructd with different constructors.");
}

void test_clone_returns_same_hash_float_array() {
    float i1 = 1.1;
    float* o = &i1;
    FloatArray* a = new FloatArray();
    a->push_back(o);
    FloatArray* b = a->clone();
    s.t_true(a->equals(b));
    s.OK("Clone returns new float with same hash.");
}


void test_clone_not_same_after_adding_new_item_float_array() {
    float i1 = 1.1;
    float i2 = 2.2;
    float* o = &i1;
    float* p = &i2;
    FloatArray* a = new FloatArray();
    a->push_back(o);
    FloatArray* b = a->clone();
    a->push_back(p);

    s.t_false(a->equals(b));
    s.OK("Clone has different hash than original after adding item to orig.");
}


void test_add_all_works_float_array() {
    float i1 = 1.1;
    float i2 = 2.2;
    float i3 = 3.3;
    float* o = &i1;
    float* p = &i2;
    float* q = &i3;
    FloatArray* a = new FloatArray(3);
    FloatArray* b = new FloatArray();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->add_all(0,a);
    
    s.t_true(a->equals(b));
    s.OK("Test add all works");
}


void test_size_empty_float_array() {
    FloatArray* a = new FloatArray();
    s.t_true(a->size() == 0);
    s.OK("Size is empty correctly");
}

void test_size_not_empty_float_array() {
    float i1 = 1.1;
    float i2 = 2.2;
    float i3 = 3.3;
    float* o = &i1;
    float* p = &i2;
    float* q = &i3;
    FloatArray* a = new FloatArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    s.t_true(a->size() == 3);
    s.OK("size not empty correct");
}

void test_get_returns_same_float_array() {
    float i1 = 1.1;
    float i2 = 2.2;
    float i3 = 3.3;
    float* o = &i1;
    float* p = &i2;
    float* q = &i3;
    FloatArray* a = new FloatArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    s.t_true(a->get(0) == o);
    s.t_false(a->get(1) == o);
    s.t_true(a->get(1) == q);
    s.t_false(a->get(0) == q);
    s.t_true(a->get(2) == p);

    s.OK("Get returns correct floats");
}


void test_clear_correctly_empties_entire_FloatArray() {
    float i1 = 1.1;
    float i2 = 2.2;
    float i3 = 3.3;
    float* o = &i1;
    float* p = &i2;
    float* q = &i3;
    FloatArray* a = new FloatArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    a->clear();

    s.t_true(a->get(0) == nullptr);
    s.t_true(a->get(1) == nullptr);
    s.t_true(a->get(2) == nullptr);
    s.OK("FloatArray is clear");
}


// BoolArray


void test_empty_BoolArray_equals_empty_BoolArray() {
    BoolArray* a = new BoolArray();
    BoolArray* b = new BoolArray();
    s.t_true(a->equals(b));
    s.OK("two empty BoolArrays are equal");
}

void test_BoolArray_equals() {
    bool i1 = true;
    bool i2 = false;
    bool* o = &i1;
    bool* p = &i2;
    BoolArray* a = new BoolArray();
    BoolArray* b = new BoolArray();
    a->push_back(o);
    a->push_back(p);
    b->push_back(o);
    b->push_back(p);
    s.t_true(a->equals(b));
    s.OK("two BoolArrays with the same bools have same hash");
}

void test_BoolArrays_are_not_equal() {
    bool i1 = true;
    bool i2 = false;
    bool* o = &i1;
    bool* p = &i2;
    BoolArray* a = new BoolArray();
    BoolArray* b = new BoolArray();
    a->push_back(o);
    b->push_back(p);
    s.t_false(a->equals(b));
    s.OK("Two different BoolArrays have different hash values.");
}

void test_constructor_equal_BoolArrays() {
    bool i1 = true;
    bool i2 = false;
    bool i3 = true;
    bool* o = &i1;
    bool* p = &i2;
    bool* q = &i3;
    
    BoolArray* a = new BoolArray(3);
    BoolArray* b = new BoolArray();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->push_back(o);
    b->push_back(q);
    b->push_back(p);
    
    s.t_true(a->equals(b));
    s.OK("Two BoolArrays constructd with different constructors.");
}

void test_clone_returns_same_hash_bool_array() {
    bool i1 = true;
    bool* o = &i1;
    BoolArray* a = new BoolArray();
    a->push_back(o);
    BoolArray* b = a->clone();
    s.t_true(a->equals(b));
    s.OK("Clone returns new bool with same hash.");
}


void test_clone_not_same_after_adding_new_item_bool_array() {
    bool i1 = true;
    bool i2 = false;
    bool* o = &i1;
    bool* p = &i2;
    BoolArray* a = new BoolArray();
    a->push_back(o);
    BoolArray* b = a->clone();
    a->push_back(p);

    s.t_false(a->equals(b));
    s.OK("Clone has different hash than original after adding item to orig.");
}

void test_add_all_works_bool_array() {
    bool i1 = true;
    bool i2 = false;
    bool i3 = true;
    bool* o = &i1;
    bool* p = &i2;
    bool* q = &i3;
    BoolArray* a = new BoolArray(3);
    BoolArray* b = new BoolArray();
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    b->add_all(0,a);
    
    s.t_true(a->equals(b));
    s.OK("Test add all works");
}

void test_size_empty_bool_array() {
    BoolArray* a = new BoolArray();
    s.t_true(a->size() == 0);
    s.OK("Size is empty correctly");
}

void test_size_not_empty_bool_array() {
    bool i1 = true;
    bool i2 = false;
    bool i3 = true;
    bool* o = &i1;
    bool* p = &i2;
    bool* q = &i3;
    BoolArray* a = new BoolArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);
    s.t_true(a->size() == 3);
    s.OK("size not empty correct");
}

void test_get_returns_same_bool_array() {
    bool i1 = true;
    bool i2 = false;
    bool i3 = true;
    bool* o = &i1;
    bool* p = &i2;
    bool* q = &i3;
    BoolArray* a = new BoolArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    s.t_true(a->get(0) == o);
    s.t_false(a->get(1) == o);
    s.t_true(a->get(1) == q);
    s.t_false(a->get(0) == q);
    s.t_true(a->get(2) == p);

    s.OK("Get returns correct bools");
}



void test_clear_correctly_empties_entire_BoolArray() {
    bool i1 = true;
    bool i2 = false;
    bool i3 = true;
    bool* o = &i1;
    bool* p = &i2;
    bool* q = &i3;
    BoolArray* a = new BoolArray(3);
    a->add(0,o);
    a->add(1,q);
    a->add(2,p);

    a->clear();

    s.t_true(a->get(0) == nullptr);
    s.t_true(a->get(1) == nullptr);
    s.t_true(a->get(2) == nullptr);
    s.OK("BoolArray is clear");
}


void test_array() {
    test_empty_array_equals_empty_array();
    test_array_equals();
    test_arrays_are_not_equal();
    test_array_hash();
    test_constructor_equal_arrays();
    test_clone_returns_same_hash();
    test_clone_not_same_after_adding_new_item_array();
    test_add_all_works();
    test_size_empty();
    test_size_not_empty();
    test_get_returns_same_object();


    test_clear_correctly_empties_entire_array();
}


void test_str_array() {
    test_empty_StrArray_equals_empty_StrArray();
    test_StrArray_equals();
    test_StrArrays_are_not_equal();
    test_constructor_equal_StrArrays();
    test_clone_returns_same_hash_str_array();
    test_clone_not_same_after_adding_new_item_str_array();
    test_add_all_works_str_array();
    test_size_empty_str_array();
    test_size_not_empty_str_array();
    test_get_returns_same_String_str_array();


    test_clear_correctly_empties_entire_StrArray();
}

void test_int_array() {
    test_empty_IntArray_equals_empty_IntArray();
    test_IntArray_equals();
    test_IntArrays_are_not_equal();
    test_constructor_equal_IntArrays();
    test_clone_returns_same_hash_int_array();
    test_clone_not_same_after_adding_new_item_int_array();
    test_add_all_works_int_array();
    test_size_empty_int_array();
    test_size_not_empty_int_array();
    test_get_returns_same_int_array();


    test_clear_correctly_empties_entire_IntArray();
}

void test_bool_array() {
    test_empty_BoolArray_equals_empty_BoolArray();
    test_BoolArray_equals();
    test_BoolArrays_are_not_equal();
    test_constructor_equal_BoolArrays();
    test_clone_returns_same_hash_bool_array();
    test_clone_not_same_after_adding_new_item_bool_array();
    test_add_all_works_bool_array();
    test_size_empty_bool_array();
    test_size_not_empty_bool_array();
    test_get_returns_same_bool_array();


    test_clear_correctly_empties_entire_BoolArray();
}

void test_float_array() {
    test_empty_FloatArray_equals_empty_FloatArray();
    test_FloatArray_equals();
    test_FloatArrays_are_not_equal();
    test_constructor_equal_FloatArrays();
    test_clone_returns_same_hash_float_array();
    test_clone_not_same_after_adding_new_item_float_array();
    test_add_all_works_float_array();
    test_size_empty_float_array();
    test_size_not_empty_float_array();
    test_get_returns_same_float_array();


    test_clear_correctly_empties_entire_FloatArray();
}

int main(int argc, char** argv) {
    test_array();
    test_str_array();
    test_int_array();
    test_bool_array();
    test_float_array();
    
}





