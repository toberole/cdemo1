#include "demo2/test_demo2.h"

#include <string>
#include <iostream>

#include "demo2/demo2_1.h"
#include "demo2/A.h"
#include <vector>

void test1_demo2() {
    std::cout << demo2_g_n << std::endl;

    std::string s("123");
}

void test2_demo2() {
    A a;
    std::vector<A> v;
    v.push_back(a);
    v.push_back(a);

    std::vector<A> v1 = v;

    std::shared_ptr<int> sp(new int[10], [](int *p) { delete[]p; });
}

void test3_demo2() {
    A a;// 调用默认构造函数
    A a1 = a;// 调用拷贝构造函数

    a = a1;// 调用赋值运算符构造函数

    a.a1();
}

