#include "demo2/A.h"
#include <iostream>

void A::a1() {
    std::cout << "a1() ......" << std::endl;
}

A::A() {
    std::cout << "A() ......" << std::endl;
}

/**
 * 如果成员是const、引用，或者属于某种未提供默认构造函数的类类型，
 * 必须通过构造函数 初始值列表为这些成员提供初值。
 */
A::A(int n) : i(n)/* 直接初始化成员i */ {
    // 先默认初始化i，在赋值为n
    // i = n;
}

A &A::operator=(const A &a) {
    std::cout << "operator=(const A &a) ......" << std::endl;
    return *this;
}

A::A(const A &a) {
    std::cout << "A &a ......" << std::endl;
}

A::A(const A &&a) {
    std::cout << "A &&a ......" << std::endl;
}