#pragma once

#define MOVESEMANTICS
#include <string>
#include <ostream>
#include "Child.h"

class Parent {
public:
    Parent(std::string name);
    Parent(const Parent& other); // copy constructor
    virtual ~Parent();
    Parent& operator=(const Parent& other);

#ifdef MOVESEMANTICS

    Parent(Parent&& other) noexcept; // move constructor
    Parent& operator=(Parent&& other) noexcept; //move assignment operator
#endif 

    friend std::ostream& operator<<(std::ostream& os, const Parent& parent);

private:
    std::string name;
    Child* child;
};


