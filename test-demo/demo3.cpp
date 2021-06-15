#include<iostream>

void test1(){
    std::cout<<"test1 ......"<<std::endl;
    // 注意中文字符保存 前面需要加个‘L’
    char32_t ch = L'中';
    wchar_t ch1 = L'中';
}

int main(int argc, char const *argv[])
{
    std::cout<<"Hello Demo3 ......"<<std::endl;
   
    return 0;
}
