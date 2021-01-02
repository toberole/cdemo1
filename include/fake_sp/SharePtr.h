#ifndef CDEMO1_SHAREPTR_H
#define CDEMO1_SHAREPTR_H

template<class T>
class WeakPtr; //为了用weak_ptr的lock()，来生成share_ptr用，需要拷贝构造用

template<class T>
class SharePtr {
public:
    SharePtr(T *p = 0) : _ptr(p) {
        cnt = new Counter();
        if (p)
            cnt->s = 1;
        cout << "in construct " << cnt->s << endl;
    }

    ~SharePtr() {
        release();
    }

    SharePtr(SharePtr<T> const &s) {
        cout << "in copy con" << endl;
        _ptr = s._ptr;
        (s.cnt)->s++;
        cout << "copy construct" << (s.cnt)->s << endl;
        cnt = s.cnt;
    }

    SharePtr(WeakPtr<T> const &w) //为了用weak_ptr的lock()，来生成share_ptr用，需要拷贝构造用
    {
        cout << "in w copy con " << endl;
        _ptr = w._ptr;
        (w.cnt)->s++;
        cout << "copy w  construct" << (w.cnt)->s << endl;
        cnt = w.cnt;
    }

    SharePtr<T> &operator=(SharePtr<T> &s) {
        if (this != &s) {
            release();
            (s.cnt)->s++;
            cout << "assign construct " << (s.cnt)->s << endl;
            cnt = s.cnt;
            _ptr = s._ptr;
        }
        return *this;
    }

    T &operator*() {
        return *_ptr;
    }

    T *operator->() {
        return _ptr;
    }

    friend class WeakPtr<T>; //方便weak_ptr与share_ptr设置引用计数和赋值

protected:
    void release() {
        cnt->s--;
        cout << "release " << cnt->s << endl;
        if (cnt->s < 1) {
            delete _ptr;
            if (cnt->w < 1) {
                delete cnt;
                cnt = NULL;
            }
        }
    }

private:
    T *_ptr;
    Counter *cnt;
};


#endif //CDEMO1_SHAREPTR_H
