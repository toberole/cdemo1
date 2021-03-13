#include <string>
#include <stdio.h>
#include <map>
#include <iostream>

int main(int argc, char const *argv[])
{

    const char *hello = "hello world";
    std::string s(hello);

    printf("hello: %p,s: %p\n", hello, s.c_str());

    std::map<std::string, std::map<std::string, void *>> funcs;

    std::map<std::string, void *> f_map1;
    f_map1["f_map1_demo1"] = (void *)"demo1";

    funcs["f_map1_key"] = f_map1;

    std::cout<<f_map1["f_map1_demo1"] << std::endl;

    return 0;
}
