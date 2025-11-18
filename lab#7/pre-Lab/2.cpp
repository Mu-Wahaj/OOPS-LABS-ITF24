#pragma once
#include <iostream>

class ImmutableItem {
private:
    const int id;
    char* label;            // deep-copied C-style string

public:
    // Constructor (id must be initialized in init-list)
    ImmutableItem(int id, const char* label);

    // Destructor to free dynamic memory
    ~ImmutableItem();

    // Accessors (const)
    int getId() const;
    const char* getLabel() const;

    // Non-const mutator (intentionally provided to demonstrate const-object behavior)
    void changeLabel(const char* newLabel);

    // Disable copy assignment and copy construction if you want true immutability for id,
    // but here we allow default behaviour (shallow copy would be wrong). We'll implement
    // copy constructor and assignment if needed later.
};
//.cpp

#include "ImmutableItem.h"
#include <cstring>

// Constructor: initialize const id via init-list and deep-copy label
ImmutableItem::ImmutableItem(int id_, const char* label_)
: id(id_)
, label(nullptr)
{
    if (label_ != nullptr) {
        size_t len = std::strlen(label_);
        label = new char[len + 1];
        std::strcpy(label, label_);
    } else {
        label = new char[1];
        label[0] = '\0';
    }
}

// Destructor: free allocated memory
ImmutableItem::~ImmutableItem() {
    delete[] label;
}

// Accessors
int ImmutableItem::getId() const {
    return id;
}

const char* ImmutableItem::getLabel() const {
    return label;
}

// Non-const mutator: changes label (demonstrates why const-object cannot call it)
void ImmutableItem::changeLabel(const char* newLabel) {
    // free old
    delete[] label;
    if (newLabel) {
        size_t len = std::strlen(newLabel);
        label = new char[len + 1];
        std::strcpy(label, newLabel);
    } else {
        label = new char[1];
        label[0] = '\0';
    }
}
//.main
#include "ImmutableItem.h"

int main() {
    // Create a const ImmutableItem
    const ImmutableItem item(5, "Test");

    // Allowed: calling const member functions on a const object
    std::cout << "Item ID: " << item.getId() << std::endl;
    std::cout << "Item Label: " << item.getLabel() << std::endl;

    // Not allowed: cannot call non-const member on a const object.
    // The following line would fail to compile:
    //
    //    item.changeLabel("NewLabel");
    //
    // Reason: item is const, so only member functions marked 'const' can be invoked.
    // changeLabel(...) is non-const because it modifies the object's state (label).
    // Trying to call it results in a compiler error like:
    // "error: passing 'const ImmutableItem' as 'this' argument discards qualifiers"
    //
    // To demonstrate changeLabel working, use a non-const instance:

    ImmutableItem mutableItem(7, "Original");
    std::cout << "Before change: " << mutableItem.getLabel() << std::endl;
    mutableItem.changeLabel("Changed");
    std::cout << "After change : " << mutableItem.getLabel() << std::endl;

    return 0;
}
