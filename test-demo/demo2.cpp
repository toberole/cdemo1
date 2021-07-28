#include <stdio.h>
#include <initializer_list>
#include <string.h>

const int k = 0;

class A
{
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

class B : public A
{
public:
    B()
    {
        printf("B() ......\n");
    }
    ~B()
    {
        printf("~B() ......\n");
    }
};

void test()
{
    // A *arr = new A[10];
    // delete[] arr;
    auto arr = {1, 2, 3};
    char *chs = "Hello";
    printf("chs size: %d\n", sizeof(chs));
    int len = strlen(chs);
    printf("chs size: %d\n", len);

    B b;
}

void test1()
{
    int i = 0;
    int &ii = i;
    int k = 100;
    ii = k;

    printf("k: %d\n", ii);

    //std::share_ptr<A> a = std::make_sha
}

int main(int argc, char const *argv[])
{

    // test();
    test1();
    return 0;
}
