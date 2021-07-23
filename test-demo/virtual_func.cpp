#include <stdio.h>

class A
{
public:
    virtual void a()
    {
        printf("A#a ......\n");
    }
};

class B :public A
{
private:
public:
    void a()
    {
        printf("B#a ......\n");
    }
};

void test1()
{
    A *p = new A;
    p->a();
    p = new B;
    p->a();
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
