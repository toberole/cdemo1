#ifndef CDEMO1_A_H
#define CDEMO1_A_H

class A {

private:
    int i;

public:
    A();

    A(int n);

    A(const A &a);

    A &operator=(const A &a);

    A(const A &&a);

    static void a1();

};


#endif //CDEMO1_A_H
