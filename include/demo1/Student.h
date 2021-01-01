#ifndef CDEMO1_STUDENT_H
#define CDEMO1_STUDENT_H


class Student {
public:
    Student();

    Student(const Student &student);

    Student(const Student &&student);

    Student operator=(Student &student);

    ~Student();

};


#endif //CDEMO1_STUDENT_H
