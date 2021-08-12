#include <stdio.h>
#include <memory>

class Demo3_Class {
private:
    const int i;
public:
    /**
     * 当类包含const成员，引用成员时
     * 只能用构造函数初始化列表而不能用赋值初始化
     */
    Demo3_Class(int i) : i(i) {
        printf("Demo3_Class i: %d ......\n", i);
    }

//    Demo3_Class() {
//        printf("Demo3_Class ......\n");
//    }

    void printInfo() {
        printf("Demo3_Class info ......\n");
    }

    ~Demo3_Class() {
        printf("~Demo3_Class ......\n");
    }
};

void test1_demo3() {
//    std::auto_ptr<Demo3_Class> p(new Demo3_Class);

    std::shared_ptr<Demo3_Class> p1 = std::make_shared<Demo3_Class>();
    p1->printInfo();
    std::unique_ptr<Demo3_Class> p2(new Demo3_Class);
    Demo3_Class *pp = p2.get();

    std::weak_ptr<Demo3_Class> wp(p1);
    wp.expired();
}

void test2_demo3() {

}

