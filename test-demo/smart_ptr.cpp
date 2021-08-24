#include <stdio.h>
#include <memory>
#include <iostream>

/**
 * std::weak_ptr 每次 lock() 都会导致自身use_count自增一次
 */
void test1()
{
    std::shared_ptr<int> a(new int(1));
    std::weak_ptr<int> d(a);
    std::cout << "weak_ptr use_count() = " << d.use_count() << std::endl;
    std::cout << "shared_ptr use_count() = " << d.use_count() << std::endl;

    std::cout << "lock ......" << std::endl;
    std::shared_ptr<int> b = d.lock();
    std::cout << "weak_ptr use_count() = " << d.use_count() << std::endl;
    std::cout << "shared_ptr use_count() = " << d.use_count() << std::endl;

    std::cout << "lock ......" << std::endl;
    std::shared_ptr<int> c = d.lock();
    std::cout << "weak_ptr use_count() = " << d.use_count() << std::endl;
    std::cout << "shared_ptr use_count() = " << d.use_count() << std::endl;
}
void test2_2()
{
    std::shared_ptr<Demo> d = std::make_shared<Demo>(1);
    std::weak_ptr<Demo> wd = d;
    // 如果当前 weak_ptr 已经过期，
    // 则该函数会返回一个空的 shared_ptr 指针；
    // 反之，该函数返回一个和当前 weak_ptr 指向相同的 shared_ptr 指针,背引用对象计数+1。
    // 使用lock是线程安全的 一般建议使用该方法
    std::shared_ptr<Demo> sd = wd.lock();
    if (sd)
    {
        // TODO
        sd->print();
    }

    // 判断当前 weak_ptr 指针为否过期（指针为空，或者指向的堆内存已经被释放）
    if (wd.expired())
    {
        // TODO 非线程安全的 多线程情况下有可能expired判断可用，但是使用的却已经不可用了
        // 注意此时wd.lock()可能出问题
        std::shared_ptr<Demo> sd = wd.lock();
    }
}
int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
