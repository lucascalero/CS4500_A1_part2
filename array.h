#pragma once
//Lang:: CwC
#include <stdio.h>
#include "object.h"

class Array: public Object{

public:

    //Constructor to create an Array with a specific size.
    Array(size_t size);

    // Creates an array object with size=0 and default hash (0)
    Array(); 

    // Destructor
    virtual ~Array();

    // Checks for equality, will cast to an Array.
    virtual bool equals(void* other);

    // Copies each pointer inside this array into a new array pointers in
    // the same order, where each pointer will be cloned and will have the
    // same hash values.
    virtual Array* clone();

    // Adds void* e at index i
    void add(size_t i, void* e);

    // Adds void* e at the end of this array. This is the only way to increase the size of this array
    void push_back(void* e);

    //Adds all the voids inside arr at the index given. If index > size()
    // Then just adds at the end of this array. Must check for type before adding.
    void add_all(size_t index, Array* arr); 

    // Returns the index of void o, if o is not in the array then return size()
    size_t index_of(void* o);

    // Returns the size of this array.
    size_t size();

    // Returns a pointer to the void* at index 
    virtual void* get(size_t index);

    // Removes the void at the index
    virtual void* remove(size_t index);
    
    // This method deletes all the voids in this array and leaves it empty.
    void clear();

    // Prints a complete representation of this void.
    void print();

    // This method returns the hash value that uniquely represents 
    // this Array
    size_t hash();
};


class StrArray : public Array {

public:

    StrArray(size_t size);

    StrArray();

    // Copies each void inside this array into a new array void in
    // the same order, where each void will be cloned and will have the
    // same hash values.
    virtual StrArray* clone();

    //Removes the string at the index and returns is. 
    String* remove(size_t index);


    String* get(size_t index);


};


class IntArray : public Array {

public:

    IntArray(size_t size);

    IntArray();

    // Copies each void inside this array into a new array void in
    // the same order, where each void will be cloned and will have the
    // same hash values.
    virtual IntArray* clone();

    //Removes the string at the index and returns is. 
    int* remove(size_t index);

    int* get(size_t index);

};

class FloatArray : public Array {

public:

    FloatArray(size_t size);

    FloatArray();

    // Copies each void inside this array into a new array void in
    // the same order, where each void will be cloned and will have the
    // same hash values.
    virtual FloatArray* clone();

    //Removes the string at the index and returns is. 
    float* remove(size_t index);

    float* get(size_t index);

};

class BoolArray : public Array {

public:

    BoolArray(size_t size);

    BoolArray();

    // Copies each void inside this array into a new array void in
    // the same order, where each void will be cloned and will have the
    // same hash values.
    virtual BoolArray* clone();

    //Removes the string at the index and returns is. 
    bool* remove(size_t index);

    bool* get(size_t index);

};
