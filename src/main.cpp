#include <iostream>
#include "demo1/smart_ptr.h"
#include "demo1/stl_demo.h"
#include "demo1/constructor_demo.h"
#include "demo1/MyStr.h"
#include "demo1/file_demo.h"
#include "demo1/cpp_base_test.h"
#include "demo1/lambda_demo.h"
#include "demo1/thread_demo.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    sizeof_demo();
//    mem_demo();
//    thread_demo2();
//    thread_demo1();
//    lambda_demo1();
//    string_view_demo();
//    variant_demo1();
//    file_demo1();
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

    std::cout << "press any key to exit ......" << std::endl;
    std::cin.get();
    return 0;
}