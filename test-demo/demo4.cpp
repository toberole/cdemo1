#include <stdio.h>

/**
 * 必须用到初始化成员列表
 * 
 * 类的成员是常量成员初始化 
 * 类的成员是对象成员初始化，而该对象没有无参构造函数 
 * 类的成员为引用时 
 */
class A
{
private:
    int i = 0;

public:
    A(int i) : i(i)
    {
    }
    ~A()
    {
    }

    void test()
    {
    }
};

class demo4
{
private:
    A a;

public:
    demo4(A a) : a(a)
    {
    }
    ~demo4()
    {
    }
};

int main(int argc, char const *argv[])
{
    char str[32] = "abcd";
    for (int i = 0; i < 32;)
    {
        printf("%c_%c\n", str[i], str[i++]);
    }

    return 0;
}