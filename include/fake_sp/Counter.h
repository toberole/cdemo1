#ifndef CDEMO1_COUNTER_H
#define CDEMO1_COUNTER_H


class Counter
{
public:
    Counter() : s(0), w(0){};
    int s;	//share_ptr的引用计数
    int w;	//weak_ptr的引用计数
};



#endif //CDEMO1_COUNTER_H
