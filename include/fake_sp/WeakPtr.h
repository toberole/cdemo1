#ifndef CDEMO1_WEAKPTR_H
#define CDEMO1_WEAKPTR_H

template<class T>
class WeakPtr {
public: //给出默认构造和拷贝构造，其中拷贝构造不能有从原始指针进行构造
    WeakPtr() {
        _ptr = 0;
        cnt = 0;
    }

    WeakPtr(SharePtr <T> &s) : _ptr(s._ptr), cnt(s.cnt) {
        cout << "w con s" << endl;
        cnt->w++;
    }

    WeakPtr(WeakPtr<T> &w) : _ptr(w._ptr), cnt(w.cnt) {
        cnt->w++;
    }

    ~WeakPtr() {
        release();
    }

    WeakPtr<T> &operator=(WeakPtr<T> &w) {
        if (this != &w) {
            release();
            cnt = w.cnt;
            cnt->w++;
            _ptr = w._ptr;
        }
        return *this;
    }

    WeakPtr<T> &operator=(SharePtr <T> &s) {
        cout << "w = s" << endl;
        release();
        cnt = s.cnt;
        cnt->w++;
        _ptr = s._ptr;
        return *this;
    }

    SharePtr <T> lock() {
        return SharePtr<T>(*this);
    }

    bool expired() {
        if (cnt) {
            if (cnt->s > 0) {
                cout << "empty" << cnt->s << endl;
                return false;
            }
        }
        return true;
    }

    friend class SharePtr<T>; //方便weak_ptr与share_ptr设置引用计数和赋值

protected:
    void release() {
        if (cnt) {
            cnt->w--;
            cout << "weakptr release" << cnt->w << endl;
            if (cnt->w < 1 && cnt->s < 1) {
                //delete cnt;
                cnt = NULL;
            }
        }
    }

private:
    T *_ptr;
    Counter *cnt;
};


#endif //CDEMO1_WEAKPTR_H
