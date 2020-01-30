#pragma once
//Lang:: CwC
#include <stdio.h>
#include "object.h"

class Array: public Object{

public:

    size_t size_;
    size_t capacity_;
    size_t hash_;

    //Constructor to create an Array with a specific size.
    Array(size_t size);

    // Creates an array object with size=0 and default hash (0)
    Array(); 

    // Destructor
    virtual ~Array();

    // Checks for equality, will cast to an Array.
    virtual bool equals(Object* other);

    // Copies each object inside this array into a new array object in
    // the same order, where each object will be cloned and will have the
    // same hash values.
    Array* clone();

    // Adds Object* e at index i
    virtual void add(size_t i, Object* e);

    // Adds Object* e at the end of this array. This is the only way to increase the size of this array
    virtual void push_back(Object* e);

    //Adds all the objects inside arr at the index given. If index > size()
    // Then just adds at the end of this array.
    virtual void add_all(size_t index, Array* arr);

    // Returns the index of Object o, if o is not in the array then return size()
    virtual size_t index_of(Object* o);

    // Returns the size of this array.
    size_t size();

    // Returns a pointer to the Object* at index
    virtual Object* get(size_t index);

    // Removes the object at the index
    virtual Object* remove(size_t index);
    
    // This method deletes all the objects in this array and leaves it empty.
    void clear();

    // Prints a complete representation of this object.
    void print();

    // This method returns the hash value that uniquely represents 
    // this Array
    size_t hash();
};


class StrArray : public Array {

public:
    size_t size_;
    size_t capacity_;
    size_t hash_;

    //Constructor to create an Array with a specific size.
    StrArray(size_t size);

    // Creates an StrArray object with size=0 and default hash (0)
    StrArray(); 

    // Destructor
    virtual ~StrArray();

    // Checks for equality, will cast to an StrArray.
    bool equals(Object* other);

    // Adds Object* e at index i. Will cast object to string.
    virtual void add(size_t i, Object* e);

    // Adds Object* e at the end of this StrArray. This is the only way to increase the size of this StrArray.
    // Will cast to String* first
    virtual void push_back(Object* e);

    //Adds all the objects inside arr at the index given. If index > size()
    // Then just adds at the end of this StrArray.
    virtual bool add_all(size_t index, StrArray* arr);

    // Returns the index of Object o, if o is not in the StrArray or Object not a string
    // then return size()
    virtual size_t index_of(Object* o);

    // Returns the size of this StrArray.
    virtual size_t size();

    // Returns a pointer to the Object* at index.
    virtual Object* get(size_t index);

    // Removes the object at the index
    virtual Object* remove(size_t index);
    
    // This method deletes all the objects in this StrArray and leaves it empty.
    virtual void clear();

    // Prints a complete representation of this object.
    virtual void print();

    // This method returns the hash value that uniquely represents 
    // this StrArray
    virtual size_t hash();
};
