#ifndef CDEMO1_STUDENT_H
#define CDEMO1_STUDENT_H


class Student {
public:
    Student();

    Student(const Student &stu);

    Student(const Student &&student);

    ~Student();

};


#endif //CDEMO1_STUDENT_H
