#include <stdio.h>
#include <functional>
#include <thread>
#include <exception>
#include <iostream>

void f1()
{
    printf("f1 ......\n");
}

void f2(int n1, int n2, const char *s)
{
    printf("f2 n1: %d,n2: %d,s: %s\n", n1, n2, s);
}

void test()
{
    try
    {
        int i = 0;
        int *p = &i;
        char *ch_p = (char *)p;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    /*
        static_cast 用于良性转换，一般不会导致意外发生，风险很低。
        const_cast 用于 const 与非 const、volatile 与非 volatile 之间的转换。
        reinterpret_cast 高度危险的转换，这种转换仅仅是对二进制位的重新解释，不会借助已有的转换规则对数据进行调整，但是可以实现最灵活的 C++ 类型转换。
        dynamic_cast 借助 RTTI，用于类型安全的向下转型（Downcasting）。
    */
    /**
     * const_cast
     * const_cast，用于修改类型的const或volatile属性。
     * 该运算符用来修改类型的const(唯一有此能力的C++-style转型操作符)或volatile属性。
     * 除了const 或volatile修饰之外，new_type和expression的类型是一样的。
     *  ①常量指针被转化成非常量的指针，并且仍然指向原来的对象；
     *  ②常量引用被转换成非常量的引用，并且仍然指向原来的对象；
     *  ③const_cast一般用于修改底指针。如const char *p形式。
     * */
    // const int g = 20;
    // 去掉const常量const属性
    // int *h = const_cast<int *>(&g);

    // const int g = 20;
    // 去掉const引用const属性
    // int &h = const_cast<int &>(g);

    // const char *g = "hello";
    // 去掉const指针const属性
    // char *h = const_cast<char *>(g);
}

int main(int argc, char const *argv[])
{
    /**
     * std::bind返回一个基于f的函数对象，其参数被绑定到args上。
     * f的参数要么被绑定到值，要么被绑定到placeholders（占位符，如_1, _2, ..., _n）。
    */

    auto test1 = std::bind(f2, 1, 2, "Hello");
    test1();

    auto test2 = std::bind(f2, std::placeholders::_1, 2, "Hello");
    test2(111);

    std::thread th(test1);
    th.join();

    return 0;
}
