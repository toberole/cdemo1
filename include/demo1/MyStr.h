#ifndef CDEMO1_MYSTR_H
#define CDEMO1_MYSTR_H

#include<iostream>
#include<string>

using namespace std;

class MyStr {
private:
    char *name;
    int id;
public:
    MyStr() : id(0), name(NULL) {}

    MyStr(int _id, char *_name)   //constructor
    {
        cout << "constructor" << endl;
        id = _id;
        name = new char[strlen(_name) + 1];
//        strcpy_s(name, strlen(_name) + 1, _name);
    }

    MyStr(const MyStr &str) {
        cout << "copy constructor" << endl;
        id = str.id;
        name = new char[strlen(str.name) + 1];
//        strcpy_s(name, strlen(str.name) + 1, str.name);
    }

    MyStr &operator=(const MyStr &str)//赋值运算符
    {
        cout << "operator =" << endl;
        if (this != &str) {
            if (name != NULL)
                delete[] name;
            this->id = str.id;
            int len = strlen(str.name);
            name = new char[len + 1];
//            strcpy_s(name, strlen(str.name) + 1, str.name);
        }
        return *this;
    }

    ~MyStr() {
        delete[] name;
    }
};

#endif //CDEMO1_MYSTR_H
