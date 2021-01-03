#ifndef CDEMO1_CONSTRUCTOR_DEMO_H
#define CDEMO1_CONSTRUCTOR_DEMO_H


class constructor_demo {
public:
    int i;
public:
    constructor_demo();

    constructor_demo(const constructor_demo &constructorDemo);

    constructor_demo(const constructor_demo &&constructorDemo);

    constructor_demo &operator=(const constructor_demo &constructorDemo);

    void test();

    ~constructor_demo();
};

void constructor_demo_test();


#endif //CDEMO1_CONSTRUCTOR_DEMO_H
