#include "inheritance.h"
#include "inheritance.cpp"
int main() {
    Base *p = new Base;
    Base *p2 = new Derived;
    p->print();
    p2->print();
    delete p;
    delete p2;
	return 0;
}

