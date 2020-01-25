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

    // creates another identical object with a different hash
    virtual Object* clone();

    // returns a char* (string) representation of this object.
    virtual char* to_string();
};


class String: public Object {
    public:
        String() {

        }

        String(char* val) {}

        String(const char* val) {}


        ~String() {}

        virtual bool equals(Object* other);

        String* concat(String* s);

        virtual Object* clone();

        int compare_to(Object* other);

        bool contains(String* s);
};