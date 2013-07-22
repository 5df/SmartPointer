#include "SmartPointer1.h"

template <typename T>
SmartPointer1<T>::SmartPointer1(T *ptr=0) : counter(0)
{
    if(ptr)
    {
        counter=new Counter(ptr,1);
    }
}

template <typename T>
SmartPointer1<T>::~SmartPointer1()
{
    release();
}

template <typename T>
SmartPointer1<T>::SmartPointer1(const SmartPointer1<T>& o)
{
    acquire(o.counter);
}

template <typename T>
T* SmartPointer1<T>::operator->()
{
    return counter->p;
}

template <typename T>
T& SmartPointer1<T>::operator* ()
{
    return  *counter->p;
}

template <typename T>
SmartPointer1<T>&
SmartPointer1<T>::operator=(const SmartPointer1<T>& o)
        {
            if (this != &o)
            {
                release();
                acquire(o.counter);
            }
            return *this;
        }


template <typename T>
void SmartPointer1<T>::acquire(Counter *c)
{
    counter = c;
    if (c) ++c->count;
}


template <typename T>
void SmartPointer1<T>::release()
{
    if (counter) {
        if (--counter->count == 0) {
            delete counter->p;
            delete counter;
            counter = 0;
        }
    }
}
