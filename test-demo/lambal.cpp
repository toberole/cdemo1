#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/**
 * Lambda表达式完整的声明格式如下：
 * [capture list] (params list) mutable exception-> return type { function body }
 *      capture list：捕获外部变量列表
 *      params list：形参列表
 *      mutable指示符：用来说用是否可以修改捕获的变量
 *      exception：异常设定
 *      return type：返回类型
 *      function body：函数体
 * 
 * 省略其中的某些成分来声明“不完整”的Lambda表达式，常见的有以下几种：
 *      1	[capture list] (params list) -> return type {function body}
 *      2	[capture list] (params list) {function body}
 *      3	[capture list] {function body}
 * 
 * 在Lambda表达式中，外部变量的捕获方式也有值捕获、引用捕获、隐式捕获。
 * 1、值捕获
 *      值捕获和参数传递中的值传递类似，被捕获的变量的值在Lambda表达式创建时通过值拷贝的方式传入，因此随后对该变量的修改不会影响影响Lambda表达式中的值。
 * 
 * 2、引用捕获
 *      使用引用捕获一个外部变量，只需要在捕获列表变量前面加上一个引用说明符&
 * 
 * 3、隐式捕获
 *      编译器根据函数体中的代码来推断需要捕获哪些变量，这种方式称之为隐式捕获。
 *      隐式捕获有两种方式: [=]和[&]
 *      [=] 表示以值捕获的方式捕获外部变量
 *      [&] 表示以引用捕获的方式捕获外部变量
 * 4、混合方式
 * []	不捕获任何外部变量
 * [变量名, …]	默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用&说明符）
 * [this]	以值的形式捕获this指针
 * [=]	以值的形式捕获所有外部变量
 * [&]	以引用形式捕获所有外部变量
 * [=, &x]	变量x以引用形式捕获，其余变量以传值形式捕获
 * [&, x]	变量x以值的形式捕获，其余变量以引用形式捕获
 * 
 * 修改捕获变量
 * 在Lambda表达式中，如果以传值方式捕获外部变量，则函数体中不能修改该外部变量，否则会引发编译错误。
 * 如果需要修改值捕获的外部变量：
 * 1、使用引用捕获
 * 2、使用mutable关键字，该关键字用以说明表达式体内的代码可以修改值捕获的变量
 * 
 * Lambda表达式的参数主要有以下几点：
 *      参数列表中不能有默认参数
 *      不支持可变参数
 *      所有参数必须有参数名
 * */
void test1()
{
    int i = 0;
    int n = 1;
    printf("i p: %p\n", &i);

    auto lambal1 = []() -> void
    {
        printf("lambal1 ......\n");
    };

    // 值捕获
    auto lambal2 = [i]()
    {
        printf("...... i p %p\n", &i);
    };

    // 引用捕获
    auto lambal3 = [&i]()
    {
        i++;
    };

    // 隐式捕获 值捕获
    auto lambal4 = [=]()
    {
        printf("隐式值捕获 i: %d,n: %d\n", i, n);
    };
    auto lambal5 = [&]()
    {
        i++;
        n++;
        printf("隐式引用捕获 i: %d,n: %d\n", i, n);
    };

    int k = 0;
    printf("1 ...... k address: %p\n", &k);
    auto lambal6 = [k]() mutable
    {
        // 修改K
        k++;
        printf("2 ...... k address: %p\n", &k);
    };

    int t = 9;
    auto f = [t]() mutable
    {
        return ++t;
    };
    f();

    lambal1();
    lambal2();
    lambal3();
    printf("i: %d\n", i);
    lambal4();
    lambal5();
    lambal6();
    printf("k: %d\n", k);

    printf("t: %d\n", t);
}

void test2()
{
    // 注意 mutable
    size_t t = 9;
    auto f = [t]() mutable
    { return ++t; };
    std::cout << f() << std::endl;
    std::cout << f() << std::endl;
    std::cout << "t:" << t << std::endl;

    std::cout << "########################" << t << std::endl;
    // size_t t1 = 9;
    // // cannot assign to a variable captured by copy in a non-mutable lambda
    // auto f1 = [t1](){ ++t1; };
    // f1();
    // std::cout << "t1:" << t1 << std::endl;
}

int main(int argc, char const *argv[])
{

    test2();
    return 0;
}
