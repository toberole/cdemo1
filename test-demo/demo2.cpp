#include<stdio.h>
#include<stdlib.h>
#include<string>
__attribute__((constructor)) void load_file()
{
    printf("Constructor is called.\n");
    int *g_count = (int *)malloc(sizeof(int));
}

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");
    // error
    // char*chs = nullptr;
    // std::string s = chs;

    return 0;
}
