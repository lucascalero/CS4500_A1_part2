#pragma once
#include <stdio.h>

class Object {

public:
    //Constructor
    Object();

    // Destructor
    virtual ~Object();

    // Checks for equality
    virtual bool equals(Object* other);

    // This method returns the hash value that uniquely represents 
    // this Object
    size_t hash();

    virtual Object* clone();

    virtual char* to_string();
};


class String: public Object {
    public:
        String() {

        }

        String(char* val) {}

        String(const char* val) {}


        ~String() {}


};