#include <iostream>
#include "demo1/smart_ptr.h"
#include "demo1/stl_demo.h"
#include "demo1/constructor_demo.h"
#include "demo1/MyStr.h"
#include "demo1/file_demo.h"

void test1_main() {
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

void test2_main() {
    MyStr str1(1, "hhxx");
    cout << "====================" << endl;
    MyStr str2;
    str2 = str1;
    cout << "====================" << endl;
    MyStr str3 = str2;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    file_demo1();
//    test2_main();
//    test1_main();
//    weak_ptr_demo();
//    shared_ptr_demo();
//    unique_ptr_demo();
//    auto_ptr_demo();
//    test2_main();
//    vector_demo();
//    queue_demo();

//    list_demo();
//    map_demo();
    return 0;
}