#include "SmartPointer2.h"

template <typename T>
SmartPointer2<T>::SmartPointer2(T *ptr=0) : p(ptr)
{
    prev = next = this;
}

template <typename T>
SmartPointer2<T>::~SmartPointer2()
{
    release();
}

template <typename T>
SmartPointer2<T>::SmartPointer2(const SmartPointer2& o)
{
    acquire(o);
}

template <typename T>
SmartPointer2<T>&
SmartPointer2<T>::operator=(const SmartPointer2& o)
{
    if (this != &o) {
            release();
            acquire(o);
    }
    return *this;
}

template <typename T>
T& SmartPointer2<T>::operator*()
{
    return *p;
}

template <typename T>
T* SmartPointer2<T>::operator->()
{
    return p;
}


template <typename T>
void SmartPointer2<T>::acquire(const SmartPointer2& o)
{
    // Append to the tail of doublie linked list
    p = o.p;
    next = o.next;
    next->prev = this;
    prev = &o;
    o.next = this;
}

template <typename T>
void SmartPointer2<T>::release()
{
    if (prev ? prev==this : true)
    {
        delete p;
    }
    else {
        // Get out of the double linked list
        prev->next = next;
        next->prev = prev;
        prev = next = 0;
    }
    p = 0;
}
