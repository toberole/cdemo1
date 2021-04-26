#include "demo1/Student.h"
#include <iostream>

Student::Student() {
    std::cout << "1 ......" << std::endl;
}

Student::Student(const Student &stu) {
    std::cout << "2 ......" << std::endl;
}

Student::Student(const Student &&stu) {
    std::cout << "3 ......" << std::endl;
}

Student::~Student() {
    std::cout << "4 ......" << std::endl;
}