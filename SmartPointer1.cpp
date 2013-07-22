#include "SmartPointer1.h"

/*!
 * \file SmarPointer1.cpp
 * \brief A SmartPointer implementation based on reference counter.
 * Each time a new SmartPointer instance is created trought copy constructor
 * the reference counter is incremented, and each time the instance is destroyed
 * the destructor take care of decrementing the reference counter. These two
 * operations are implemented by the privte function acquire() and delete()
 */

template <typename T>
SmartPointer1<T>::SmartPointer1(T *ptr=0) : counter(0)
{
    if(ptr)
    {
        /* If ptr is givent, then allocate a new
         * reference counter for it and set the count to 1
         */
        counter=new Counter(ptr,1);
    }
}

template <typename T>
SmartPointer1<T>::~SmartPointer1()
{
    release();
}

template <typename T>
SmartPointer1<T>::SmartPointer1(const SmartPointer1<T>& smartptr)
{
    acquire(smartptr.counter);
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
SmartPointer1<T>::operator=(const SmartPointer1<T>& smartptr)
        {
            if (this != &smartptr)
            {
                /* If the copied SmartPointer instance is not this
                 * then release this reference and acquire the smartptr
                 * one
                 */
                release();
                acquire(smartptr.counter);
            }
            return *this;
        }


template <typename T>
void SmartPointer1<T>::acquire(Counter *c)
{
    /* Make sure we point to the right reference counter */
    counter = c;
    if (c)
    {
        /* Increment the reference counter */
        ++c->count;
    }
}


template <typename T>
void SmartPointer1<T>::release()
{
    if (counter)
    {
        /* Decrement the reference counter */
        if (--counter->count == 0)
        {
            /* If no reference left, then delete the pointer
             * and the reference counter previously allocated
             * (by the constructor)
             */
            delete counter->p;
            delete counter;
            counter = 0;
        }
    }
}
