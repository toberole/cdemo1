#include "demo1/constructor_demo.h"
#include <iostream>

constructor_demo::constructor_demo() {
    std::cout << "default constructor_demo" << std::endl;
}

constructor_demo::constructor_demo(const constructor_demo &constructorDemo) {
    std::cout << "copy constructor_demo" << std::endl;
}

constructor_demo::constructor_demo(const constructor_demo &&constructorDemo) {
    std::cout << "move constructor_demo" << std::endl;
}

constructor_demo &constructor_demo::operator=(const constructor_demo &constructorDemo) {
    std::cout << "constructor_demo operator=" << std::endl;
    if (this == &constructorDemo)return *this;

    return *this;
}

void constructor_demo::test() {
    std::cout << "constructor_demo::test" << std::endl;
}

constructor_demo::~constructor_demo() {
    std::cout << "~ constructor_demo" << std::endl;
}