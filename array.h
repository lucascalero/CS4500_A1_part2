#pragma once
#include <stdio.h>
#include "object.h"

class Array: public Object{

public:

    //Constructor
    Array();

    // Automatically adds this object to the array, and determines that this is
    // an array of object pointers 
    Array(Object* o);

    //Determines that this is an array of String pointers and not object*
    Array(String* s);

    // Destructor
    virtual ~Array();

    // Checks for equality
    virtual bool equals (Object* other);

    // Copies each object inside this array into a new array object in
    // the same order, where each object will be cloned and will have the
    // same hash values.
    virtual Object* clone();

    // Returns a char* representation of this array at that point
    virtual char* to_string();

    // Adds Object e at index i, pushes all objects to the right to make space for Object
    // i.e. if o is at a[1] and you call add(1, e), then the object at a[1] will be
    // moved to a[2]
    void add(size_t i, Object* e);

    // Adds Object e at the end of this array
    void push_back(Object* e);

    //Adds all the objects inside arr at the index given. If index > size()
    // Then just adds at the end of this array.
    bool addAll(size_t index, Array* arr);

    // Returns the index of Object o, if o is not in the array then return size()
    size_t index_of(Object* o);

    // Returns the size of this array.
    size_t size();

    // Returns a pointer to the Object* at index
    Object* get(size_t index);

    // Removes the object at the index and shifts all objects with > index to the left.
    // i.e. object at a[2] will now be at a[1]
    Object* remove(size_t index);
    
    // This method deletes all the objects in this array and leaves it empty.
    void clear();
};

