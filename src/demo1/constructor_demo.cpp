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

void constructor_demo_test() {
    // 调用默认构造
    constructor_demo c;
    // 调用拷贝构造
    constructor_demo c1(c);

    // 调用move构造
    constructor_demo c2 = std::move(c1);

    constructor_demo c3;
    constructor_demo c4;
    // 调用赋值构造
    c4 = c3;
}