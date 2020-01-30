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
    virtual size_t hash();

    // creates another identical object
    virtual Object* clone();

    // Prints a complete representation of this object.
    virtual void print();
};


class String: public Object {
    public:
        String() {
        }
        String(char* val) {}

        String(const char* val) {}

        ~String() {}

        //virtual override
        bool equals(Object* other);

        String* concat(String* s);

        int compare_to(Object* other);

        bool contains(String* s);

        //virtual override
        Object* clone();

        //virtual override
        void print();
};