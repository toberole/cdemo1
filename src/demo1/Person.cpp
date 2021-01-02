#include "demo1/Person.h"
#include <iostream>
Person::Person() {
    ip = nullptr;
}

Person::Person(Person &&p) noexcept {
    ip = nullptr;
    std::cout << "移动构造 ......" << std::endl;
}

void Person::print() {
    if (ip) {
        std::cout << "ip: " << *ip << std::endl;
    }
}

Person::~Person() {

}
