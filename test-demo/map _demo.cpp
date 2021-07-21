#include <string>
#include <map>
#include <iostream>

void test1()
{
    // insert()方法：若插入的元素的键值已经存在于map中，那么插入就会失败，不会修改元素的键对应的值；若键值在map中查不到，那么就会将该新元素加到map中去。
    // 下标[key]方法：若插入元素的键值已经存在于map中，那么会更新该键值对应的值为新的元素的值；
    // 若该键值在map中找不到，那么就会新建一个键值为该键（key）的元素，并将key对应的值赋值为默认值（默认构造函数生成的对象）。

    /* 
    注意：
        数组访问会导致map膨胀，
            比如当map中不存在某一个key值时，通过数组的方式访问，
            它会将整个key值插入到map中，并且插入的value是一个默认值。
    */
    std::map<std::string, std::string> map;
    map["Hello"] = "World!";
    std::cout << map["Hello"] << std::endl;
    map.insert(std::make_pair("Hello", "123"));
    std::cout << map["Hello"] << std::endl;
    map["Hello"] = "World! 456";
    std::cout << map["Hello"] << std::endl;

    std::map<std::string, std::string>::iterator itr = map.begin();
    while (itr != map.end())
    {
        std::cout << itr->first << ": " << itr->second << std::endl;
        itr++;
    }

    std::cout << "test: " << map["Hello1"] << std::endl;
    std::cout << "test: " << map["Hello1"] << std::endl;
}
void test2()
{
    std::map<std::string, std::string> map;
    map["Hello"] = "World!";
    // Hello1 为key的元素不存在 使用下标的方式访问回到map膨胀
    std::cout << "test: " << map["Hello1"] << std::endl;
    std::cout << map.size() << std::endl; // size == 2 导致map膨胀

    std::map<std::string, std::string>::iterator itr = map.find("Hello2");
    std::cout << map.size() << std::endl; // size == 2 // 不会导致map膨胀
}
int main(int argc, char const *argv[])
{
    test2();
    return 0;
}
