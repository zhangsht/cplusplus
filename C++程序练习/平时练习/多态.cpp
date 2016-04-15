#include <iostream>
class Base {
    public:
        Base() {}
        ~Base() {
            std::cout << "~base\n";
        }
};
class Derived :public Base {
    public:
        Derived() {}
        ~Derived() {
            std::cout << "~derived\n"; 
        }
};
int main() {
    Base *p = new Derived;
    delete p;
    return 0;
} 
