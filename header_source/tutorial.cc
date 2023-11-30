#include "tutorial.h"

Concrete::Concrete() {}
Concrete::~Concrete() {}

void Concrete::abstract_method() {
    std::cout << "called Concrete::abstract_method" << std::endl;
}

void Concrete::concrete_method() {
    std::cout << "called Concrete::concrete_method" << std::endl;
}

void Concrete::array_method(int* ad, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << ad[i] << ' ';
    std::cout << '\n';
}

void Concrete::array_method(double* ad, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << ad[i] << ' ';
    std::cout << '\n';
}

void Concrete::uint_ref_assign(unsigned int& target, unsigned int value) {
    target = value;
}

Concrete::operator const char*() {
    return "Hello operator const char*!";
}
