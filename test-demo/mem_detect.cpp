#include "./mem_checker.h"
#include <stdio.h>

void test()
{
    int *p = (int*)malloc(sizeof(int));
    *p = 1;
    printf("v: %i\n", *p);
}

int main(int argc, char const *argv[])
{

    test();
    return 0;
}
