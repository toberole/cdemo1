#include <stdio.h>
#include <stdlib.h>
#include <string>

class pre_call
{
private:
public:
    pre_call()
    {
        printf("pre_call ......");
    }
    ~pre_call()
    {
        printf("~pre_call ......");
    }
};

pre_call p;

/*
    定义constructor属性的函数会放在elf文件的constructor区域，
    在链接的时候由于我们的注册函数没被调用，所以编译器很可能做优化，
    不去链接我们的注册函数，这样elf文件的constructor区域就没有我们的注册函数，
    自然注册函数就不会自动的调用了，解决办法就是在链接的时候强制把.a里所有的函数都链接到可执行文件中。
    我们使用-Wl,--whole-archive和 -Wl,--no-whole-archive这两个链接命令来做这件事情。
    --whole-archive 可以把在其后面出现的静态库包含的函数和变量输出到结果中，--no-whole-archive 则关掉这个特性。
    你不想把--whole-archive后边所有.a库的函数和变量都链接到输出结果的时候就需要用--no-whole-archive了，这里需要注意的是-wl，--whole-archive 和 --no-whole-archive 是ld专有的命令行参数，gcc 并不认识，要通gcc传递到 ld，需要在他们前面加 -Wl,例子如下:
    gcc main.o  -lb.a -wl,--whole-archive -lmode_fs.a -wl, --no-whole-archive -lc.a -lz.a -o man 
*/
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
