#include <iostream>

#include "demo1/Student.h"

void test1_main() {
//    Student student;
//    Student student1 = std::move(student);
    Student*stu = new Student();
    Student student2 = std::move(*stu);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1_main();
    return 0;
}