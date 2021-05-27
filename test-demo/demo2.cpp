#include <stdio.h>
#include <stdlib.h>
#include <string>

__attribute__((constructor)) void load_file()
{
    printf("Constructor is called.\n");
    int *g_count = (int *)malloc(sizeof(int));
}

void fun(int a, ...)
{
    int i;
    int *temp = &a;

    temp++;
    for (i = 0; i < a; i++)
    {
        printf("%d\n", *temp);
        temp--;
    }
}

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");
    // error
    // char*chs = nullptr;
    // std::string s = chs;
    fun(4, 1, 2, 3, 4);
    return 0;
}
