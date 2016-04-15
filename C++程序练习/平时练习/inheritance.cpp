#include "inheritance.h"
Base::Base() {}
void Base::print() {
    std::cout << "Base\n";
}
Base::~Base() {
    std::cout << "Base destruct\n";
}

Derived::Derived() {}
void Derived::print() {
    std::cout << "Derived\n";
}
Derived::~Derived() {
    std::cout << "Derived destruct\n";
}

