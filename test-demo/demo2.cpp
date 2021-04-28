#include<stdio.h>
#include<stdlib.h>

__attribute__((constructor)) void load_file()
{
    printf("Constructor is called.\n");
    int *g_count = (int *)malloc(sizeof(int));
}

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");
    return 0;
}
