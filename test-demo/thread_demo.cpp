#include <stdio.h>
#include <stdlib.h>
#include <thread>

void test_th1()
{
    std::this_thread::sleep_for(std::chrono::seconds(1 * 2));
    printf("test_th1 thread ......\n");
}

void test1()
{
    std::thread th(test_th1);
    // 线程默认是detach
    if (th.joinable())
    {
        th.join();
    }

    printf("test1 thread ......\n");
}
int main(int argc, char const *argv[])
{

    test1();
    return 0;
}
