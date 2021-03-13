#include "demo1/cpp_base_test.h"
#include <string>
#include <iostream>
#include <variant>

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

void mem_demo() {
    char *chs = new char[100]{0};
    // 数组内存释放
    delete[]chs;

    int *p = new int;
    *p = 110;
    delete p;
    p = nullptr;
    delete p;
}

/*
一、sizeof
    sizeof(...)是运算符，在头文件中typedef为unsigned int，其值在编译时即计算好了，参数可以是数组、指针、类型、对象、函数等。
    它的功能是：获得保证能容纳实现所建立的最大对象的字节大小。
    由于在编译时计算，因此sizeof不能用来返回动态分配的内存空间的大小。实际上，用sizeof来返回类型以及静态分配的对象、结构或数组所占的空间，返回值跟对象、结构、数组所存储的内容没有关系。
    具体而言，当参数分别如下时，sizeof返回的值表示的含义如下：
    数组——编译时分配的数组空间大小；
    指针——存储该指针所用的空间大小（存储该指针的地址的长度，是长整型，应该为4）；
    类型——该类型所占的空间大小；
    对象——对象的实际占用空间大小；
    函数——函数的返回类型所占的空间大小。函数的返回类型不能是void。
二、strlen
    strlen(...)是函数，要在运行时才能计算。参数必须是字符型指针（char*）。当数组名作为参数传入时，实际上数组就退化成指针了。
    它的功能是：返回字符串的长度。该字符串可能是自己定义的，也可能是内存中随机的，该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符NULL。返回的长度大小不包括NULL。

 */
void sizeof_demo() {
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "sizeof(arr): " << sizeof(arr) << std::endl;

    char arr1[10] = "What?";
    int len_one = strlen(arr1);
    int len_two = sizeof(arr);
    std::cout << len_one << " and " << len_two << std::endl;

    char *parr = new char[10];
    int len_one1 = strlen(parr);
    int len_two1 = sizeof(parr);
    int len_three = sizeof(*parr);
    /*
     第一个输出结果23实际上每次运行可能不一样，这取决于parr里面存了什么（从parr[0]开始知道遇到第一个NULL结束）；
     第二个结果实际上本意是想计算parr所指向的动态内存空间的大小，但是事与愿违，sizeof认为parr是个字符指针，
     因此返回的是该指针所占的空间（指针的存储用的是长整型，所以为4）;
     第三个结果，由于*parr所代表的是parr所指的地址空间存放的字符，所以长度为1。
     */
    std::cout << len_one1 << " and " << len_two1 << " and " << len_three << std::endl;
}


