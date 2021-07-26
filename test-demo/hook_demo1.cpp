#include <stdlib.h>
#include <stdio.h>

extern void *__libc_malloc(size_t size);

void *malloc(size_t size)
{
    printf("malloc ......\n");
    // do your stuff
    {
    }
    // call the original malloc
    return __libc_malloc(size);
}

int main(int argc, char const *argv[])
{

    int*p = (int*)malloc(1000);

    return 0;
}
