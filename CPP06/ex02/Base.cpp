#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate() {
    int i = std::rand() % 3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

void identify(Base *base) {
    if (dynamic_cast<A *>(base))
        std::cout << "Class A" << std::endl;
    if (dynamic_cast<B *>(base))
        std::cout << "Class B" << std::endl;
    if (dynamic_cast<C *>(base))
        std::cout << "Class C" << std::endl;
}

void identify(Base &base) {
    Base temp = base;
    try {
        base = dynamic_cast<A &>(base);
        std::cout << "Class A" << std::endl;
    } catch (const std::exception& e) {}
    try {
        base = dynamic_cast<B &>(base);
        std::cout << "Class B" << std::endl;
    } catch (const std::exception& e) {}
    try {
        base = dynamic_cast<C &>(base);
        std::cout << "Class C" << std::endl;
    } catch (const std::exception& e) {}
}

