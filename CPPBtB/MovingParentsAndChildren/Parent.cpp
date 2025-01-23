#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
    this->name = name;
    std::string childName = "ChildOf" + name;
    this->child = new Child(childName);
}

Parent::Parent(const Parent& other) {
    std::cout << "Parent cctor" << std::endl;
    this->name = other.name;
    this->child = new Child(*other.child);
}

Parent::~Parent() {
    std::cout << "Parent dtor : " << this->name << std::endl;
    delete this->child;
}

Parent& Parent::operator=(const Parent& other) {
    std::cout << "Parent assignment" << std::endl;

    if (this == &other) return *this;

    this->name = other.name;
    delete this->child;
    this->child = new Child(*other.child);

    return *this;
}

Parent::Parent(Parent&& other) noexcept
    : name(std::move(other.name)), child(other.child) {
    std::cout << "Move Constructor Call\n";

    // Reset source object
    other.child = nullptr;
    other.name = "(No Data)";
}

Parent& Parent::operator=(Parent&& other) noexcept {
    std::cout << "Move Assignment Operator Call\n";

    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Clean up existing resources
    delete child;

    // Transfer ownership
    child = other.child;
    name = std::move(other.name);

    // Reset source object
    other.child = nullptr;
    other.name = "(No Data)";

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
    os << "parent name: " << parent.name << "," << *parent.child;
    return os;
}
