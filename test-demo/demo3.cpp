#include <iostream>

void test1()
{
    std::cout << "test1 ......" << std::endl;
    // L表示双字节，也就是每个字符占用两个字节，就是可能出现中文，
    // R是里面的字符串都不转义
    // 注意中文字符保存 前面需要加个‘L’
    char32_t ch = L'中';
    wchar_t ch1 = L'中';
}

void test2()
{
    int p = 0, &i = p, *t = &p;

    int *ii = &p;
}

int main(int argc, char const *argv[])
{
    std::cout << "Hello Demo3 ......" << std::endl;

    return 0;
}
