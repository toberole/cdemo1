#include "demo1/cpp_base_test.h"
#include <variant>
#include <string>
#include <iostream>

/*
v = variant<int, double, std::string> ，则 v 是一个可存放 int, double, std::string 这三种类型数据的变体类型的对象。
v.index() 返回变体类型 v 实际所存放数据的类型的下标。
变体中第1种类型下标为0，第2种类型下标为1，以此类推。

std::holds_alternative<T>(v) 可查询变体类型 v 是否存放了 T 类型的数据。
std::get<I>(v) 如果变体类型 v 存放的数据类型下标为 I，那么返回所存放的数据，否则报错。
std::get_if<I>(&v) 如果变体类型 v 存放的数据类型下标为 I，那么返回所存放数据的指针，否则返回空指针。
std::get<T>(v) 如果变体类型 v 存放的数据类型为 T，那么返回所存放的数据，否则报错。
std::get_if<T>(&v) 如果变体类型 v 存放的数据类型为 T，那么返回所存放数据的指针，否则返回空指针。
 */
void variant_demo() {
    std::variant<int, std::string> v1{"hello"};
    // 获取实际存储值得index
    int index = v1.index();
    std::cout << "index: " << index << std::endl;
    // 判断存储的值的类型
    bool b = std::holds_alternative<int>(v1);

    v1.emplace<int>(1);

    std::variant<int, std::string> v2{1};
    v1.swap(v2);
    index = v1.index();
    std::cout << "index: " << index << std::endl;
}

void variant_demo1() {
    //define
    std::variant<int, double, std::wstring> var1{1.0};
    std::variant<int, double, std::wstring> var2{L"2"};
    std::variant<int, std::wstring> var3{3};

    //assign
    var2 = L"abc";
    var1 = L"str1";
    var2.emplace<int>(1);
    std::wcout << L"the var1 = " << std::get<std::wstring>(var1) << std::endl;
    std::wcout << L"the var2 = " << std::get<0>(var2) << std::endl;

    //swap
    std::swap(var1, var2);

    //determine the type of variant
    if (var2.index() == 2) {
        //it's wstring type
        std::wcout << L"var2 is wstring type" << std::endl;
    }
    var1 = 100;
    if (std::holds_alternative<int>(var1)) {
        std::wcout << L"var1 is " << typeid(int).name() << std::endl;
    }

    //get type by index of variant
    std::variant_alternative<2, decltype(var1)>::type val{L"123"};

    // get value
    var1 = 1;
    std::wcout << L"var1 = " << std::get<int>(var1) << std::endl;

    var2 = L"2";
    std::wcout << L"var2 = " << std::get<2>(var2) << std::endl;

    if (auto pV = std::get_if<int>(&var3)) {
        std::wcout << L"var3 = " << *pV << std::endl;
    }
}

void variant_demo2() {
    std::variant<std::monostate, int> var0;
    std::cout << var0.index() << std::endl;

    std::variant<std::monostate, double> v2; // OK
    std::cout << "index: " << v2.index() << '\n'; // prints 0

    if (v2.index() == 0) {
        std::cout << "has monostate\n";
    }
    if (!v2.index()) {
        std::cout << "has monostate\n";
    }
    if (std::holds_alternative<std::monostate>(v2)) {
        std::cout << "has monostate\n";
    }
    if (std::get_if<0>(&v2)) {
        std::cout << "has monostate\n";
    }
    if (std::get_if<std::monostate>(&v2)) {
        std::cout << "has monostate\n";
    }
}

void string_view_demo() {
    const char *cstr = "hello world!";
    std::string_view s1(cstr);
    std::string_view s2(cstr, 5);
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
}


