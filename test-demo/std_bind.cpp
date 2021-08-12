#include <stdio.h>
#include <functional>
void f1()
{
    printf("f1 ......\n");
}

void f2(int n1, int n2, const char *s)
{
    printf("f2 n1: %d,n2: %d,s: %s\n", n1, n2, s);
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

    return 0;
}
