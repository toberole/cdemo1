#ifndef CDEMO1_MAP_KEY_H
#define CDEMO1_MAP_KEY_H

// 重载运算符 "<" 的类或结构才能作为map的key值
class map_key {
public:

    int i;
public:
    map_key(int i);
    bool operator<(const map_key &k) const;
};


#endif //CDEMO1_MAP_KEY_H
