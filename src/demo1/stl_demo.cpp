#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <demo1/map_key.h>

void vector_demo() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "第一个元素：" << v.front() << std::endl;
    std::cout << "最后一个元素：" << v.back() << std::endl;

    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << std::endl;
    }
}

/**
 * queue 和 stack 有一些成员函数相似，但在一些情况下，工作方式有些不同：
 * front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
 * back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
 * push(const T& obj)：在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
 * push(T&& obj)：以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
 * pop()：删除 queue 中的第一个元素。
 * size()：返回 queue 中元素的个数。
 * empty()：如果 queue 中没有元素的话，返回 true。
 * emplace()：用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
 * swap(queue<T> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板 swap() 来完成同样的操作。
 */
void queue_demo() {
    std::queue<int> q;
    q.push(1);
    q.push(2);

    if (!q.empty()) {
        // 注意 获取第一个元素时 需要判断是否为空
        // 否则 front返回值为定义
        int i = q.front();
        std::cout << "i: " << i << std::endl;
    }

    // 遍历
    while (!q.empty()) {
        // 获取队列第一个元素
        int i = q.front();
        std::cout << "i: " << i << std::endl;
        // 删除第一个元素
        q.pop();
    }
}

/*
assign() 给list赋值
back() 返回最后一个元素
begin() 返回指向第一个元素的迭代器
clear() 删除所有元素
empty() 如果list是空的则返回true
end() 返回末尾的迭代器
erase() 删除一个元素
front() 返回第一个元素
get_allocator() 返回list的配置器
insert() 插入一个元素到list中
max_size() 返回list能容纳的最大元素数量
merge() 合并两个list
pop_back() 删除最后一个元素
pop_front() 删除第一个元素
push_back() 在list的末尾添加一个元素
push_front() 在list的头部添加一个元素
rbegin() 返回指向第一个元素的逆向迭代器
remove() 从list删除元素
remove_if() 按指定条件删除元素
rend() 指向list末尾的逆向迭代器
resize() 改变list的大小
reverse() 把list的元素倒转
size() 返回list中的元素个数
sort() 给list排序
splice() 合并两个list
swap() 交换两个list
unique() 删除list中重复的元素
 */
void list_demo() {
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);

    for (auto i = l.begin(); i != l.end(); ++i) {
        std::cout << *i << std::endl;
    }
}

#include <utility>

/*
begin()         返回指向map头部的迭代器

clear(）        删除所有元素

count()         返回指定元素出现的次数

empty()         如果map为空则返回true

end()           返回指向map末尾的迭代器

equal_range()   返回特殊条目的迭代器对

erase()         删除一个元素

find()          查找一个元素

get_allocator() 返回map的配置器

insert()        插入元素

key_comp()      返回比较元素key的函数

lower_bound()   返回键值>=给定元素的第一个位置

max_size()      返回可以容纳的最大元素个数

rbegin()        返回一个指向map尾部的逆向迭代器

rend()          返回一个指向map头部的逆向迭代器

size()          返回map中元素的个数

swap()           交换两个map

upper_bound()    返回键值>给定元素的第一个位置

value_comp()     返回比较元素value的函数
 */
void map_demo() {
    std::map<int, int> m;
    // put 元素 方式1
    m[0] = 1;
    m[1] = 2;
    // put 元素 方式2
    m.insert(std::pair<int, int>(3, 4));

    auto kv = m[1];
    std::cout << "kv: " << kv << std::endl;

    // 查找元素是否存在
    auto it = m.find(1);
    if (it != m.end()) {
        std::cout << "1 key exit" << std::endl;
        std::cout << "key: " << it->first << "value: " << it->second << std::endl;
    }

    it = m.find(5);
    if (it == m.end()) {
        std::cout << "5 key not exit" << std::endl;
    }

    std::map<map_key, int> m1;
    m1[map_key(1), 1];
}