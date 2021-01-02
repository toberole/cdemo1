#include <thread>
#include <iostream>
#include <memory>
#include "demo1/smart_ptr.h"
#include "demo1/Anim.h"

// （C++98的方案，C++11已经抛弃）采用所有权模式。
void auto_ptr_demo() {
    std::auto_ptr<Anim> p1(new Anim());
    p1->eat();
    // p2剥夺了p1的所有权，但是当程序运行时访问p1将会报错
    std::auto_ptr<Anim> p2 = p1;
    p2->eat();
    // 继续使用p1报错
    // p1->eat();
}

void unique_ptr_demo() {
    std::unique_ptr<Anim> p1(new Anim());
    // 报错
    // std::unique_ptr<Anim> p2 = p1;
    // 使用move
    std::unique_ptr<Anim> p2 = std::move(p1);

    // 当程序试图将一个 unique_ptr 赋值给另一个时，
    // 如果源 unique_ptr 是个临时右值，编译器允许这么做
    std::unique_ptr<Anim> p3 = std::make_unique<Anim>();
}

void shared_ptr_demo() {
    std::shared_ptr<Anim> p1 = std::make_shared<Anim>();
    p1->eat();

    p1 = std::make_shared<Anim>();
    std::cout << "sleep_for ......" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

/*
 weak_ptr 解决shared_ptr智能只能循环引用问题

 weak_ptr 是一种不控制对象生命周期的智能指针, 它指向一个 shared_ptr 管理的对象. 进行该对象的内存管理的是那个强引用的shared_ptr， weak_ptr只是提供了对管理对象的一个访问手段。
 weak_ptr 设计的目的是为配合 shared_ptr 而引入的一种智能指针来协助 shared_ptr 工作, 它只可以从一个 shared_ptr 或另一个 weak_ptr 对象构造, 它的构造和析构不会引起引用记数的增加或减少。
 weak_ptr是用来解决shared_ptr相互引用时的死锁问题,如果说两个shared_ptr相互引用,那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放。它是对对象的一种弱引用，不会增加对象的引用计数，
 和shared_ptr之间可以相互转化，shared_ptr可以直接赋值给它，它可以通过调用lock函数来获得shared_ptr。
 */
void weak_ptr_demo() {
    std::shared_ptr<Anim> p1(new Anim);
    // 不会增加引用计数
    std::weak_ptr<Anim> p2 = p1;
    // 使得智能指针引用计数为0 导致内存被回收
    p1 = nullptr;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    if (!p2.expired()) {// 判断内存是否被回收
        std::shared_ptr<Anim> p3 = p2.lock();
        std::cout << "count: " << p3.use_count() << std::endl;
        p3->eat();
    } else {
        std::cout << "内存被回收 ......" << std::endl;
    }
}
