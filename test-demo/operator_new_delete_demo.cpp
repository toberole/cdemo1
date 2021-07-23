#include <stdlib.h>
#include <stdio.h>
#include <new>

// #define new new(__FILE__, __LINE__)
// #include "operator_new_delete.h"

class A
{
public:
    int i = 0;

public:
    A()
    {
        printf("A() ......\n");
    }
    ~A()
    {
        printf("~A() ......\n");
    }
};
/**
 * set_new_handler
 * set_new_handler可以在malloc(需要调用set_new_mode(1))或operator new内存分配失败时指定一个入口函数new_handler，这个函数完成自定义处理(继续尝试分配，抛出异常，或终止程序)，如果new_handler返回，那么系统将继续尝试分配内存，如果失败，将继续重复调用它，直到内存分配完毕或new_handler不再返回(抛出异常，终止)。
 */

void nomem_handler()
{
    printf("call nomem_handler ......\n");
}

void test1()
{
    printf("call test1 ......\n");
    std::set_new_handler(nomem_handler);

    char *a = (char *)malloc(32 * 1024 * 1024 * 1024);
    if (a)
    {
        printf("maclloc ok ......\n");
    }
}

int main(int argc, char const *argv[])
{

    test1();
    A *p = new A;
    delete (p);
    return 0;
}
