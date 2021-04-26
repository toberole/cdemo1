#include <iostream>
#include <thread>
#include <future>

#include "demo1/thread_demo.h"

void task1() {
    std::cout << "task1 ......" << std::endl;
}

void task2(int n) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 2));
    std::cout << "task2 n: " << n << std::endl;
}

void thread_demo1() {
    std::thread th(task1);
    std::thread::id id = th.get_id();
    std::cout << "id: " << id << std::endl;
    th.join();

    std::thread th1(task2, 100);
    th1.join();
}

void thread_demo2() {
    /*
     std::launch::async：在调用async就开始创建线程。
     std::launch::deferred：延迟加载方式创建线程。调用async时不创建线程，直到调用了future的get或者wait时才创建线程。
     */
    std::future<int> f = std::async(std::launch::async, []() -> int {
        return 1024;
    });

    //查询future的状态
    std::future_status status;
    do {
        status = f.wait_for(std::chrono::seconds(1));
        if (status == std::future_status::deferred) {
            std::cout << "deferred\n";
        } else if (status == std::future_status::timeout) {
            std::cout << "timeout\n";
        } else if (status == std::future_status::ready) {
            std::cout << "ready!\n";
        }
    } while (status != std::future_status::ready);
    /*
     获取future结果有三种方式：get、wait、wait_for，
     get等待异步操作结束并返回结果
     wait只是等待异步操作完成，没有返回值，
     wait_for是超时等待返回结果。
     */

    int ret = f.get();
    std::cout << "ret: " << ret << std::endl;

    /*
     std::promise
　　 std::promise为获取线程函数中的某个值提供便利，在线程函数中给外面传进来的promise赋值，
     当线程函数执行完成之后就可以通过promis获取该值了，值得注意的是取值是间接的通过promise内部提供的future来获取的。
     */
    std::promise<int> pr;
    std::thread t([](std::promise<int> &p) { p.set_value_at_thread_exit(9); }, std::ref(pr));
    std::future<int> f1 = pr.get_future();
    auto r = f1.get();
    std::cout << "promise ret: " << r << std::endl;

    /*
     std::packaged_task
     std::packaged_task它包装了一个可调用的目标（如function, lambda expression, bind expression, or another function object）,以便异步调用，
     它和promise在某种程度上有点像，promise保存了一个共享状态的值，而packaged_task保存的是一个函数。
     */
    std::packaged_task<int()> task([]() { return 7; });
    std::thread t2(std::ref(task));
    std::future<int> f2 = task.get_future();
    auto r1 = f2.get();
    std::cout << "packaged_task ret: " << r1 << std::endl;

}