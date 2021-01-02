#include <iostream>

#include <demo1/Student.h>
#include <demo1/Person.h>

void test1_main() {
//    Student student;
//    Student student1 = std::move(student);
    Student *stu = new Student();
    Student student2 = std::move(*stu);
}

void test2_main() {
    Person p;
    int i = -1;
    p.ip = &i;
    p.print();
    Person p1 = std::move(p);
    p.print();
    p1.print();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test1_main();
    std::cout << "今天天气怎么样" << std::endl;
    return 0;
}