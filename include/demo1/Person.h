#ifndef CDEMO1_PERSON_H
#define CDEMO1_PERSON_H


class Person {
public:
    int *ip = nullptr;
public:
    Person();

    ~Person();

    Person(Person &&p)noexcept;

    void print();
};


#endif //CDEMO1_PERSON_H
