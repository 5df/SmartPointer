#include "SmartPointer2.h"

/*!
 * \file SmarPointer2.cpp
 * \brief A SmartPointer implementation based on reference linking.
 * Each time a new SmartPointer instance is created trought copy constructor
 * this instance is added to a linked list of references, and each time the
 * instance is destroyed, the destructor take care of deleting this reference of the list.
 * These two operations are implemented by the private function acquire() and delete()
 */

template <typename T>
SmartPointer2<T>::SmartPointer2(T *ptr=0) : p(ptr)
{
    /* At this time, the only reference is "this" */
    prev = next = this;
}

template <typename T>
SmartPointer2<T>::~SmartPointer2()
{
    release();
}

template <typename T>
SmartPointer2<T>::SmartPointer2(const SmartPointer2& smartptr)
{
    acquire(smartptr);
}

template <typename T>
SmartPointer2<T>&
SmartPointer2<T>::operator=(const SmartPointer2& smartptr)
{
    if (this != &smartptr) {
            /* Release "this" reference to acquire a new one */
            release();
            acquire(smartptr);
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
void SmartPointer2<T>::acquire(const SmartPointer2& smartptr)
{
    /* Here the double linked list look like this
     *
     * smartptr.prev (A) <---> smartptr <----> (B) smartptr.next
     */

    /* Get the smartptr pointer */
    p = smartptr.p;
    /* Append "this" to the double linked list */
    next = smartptr.next;
    next->prev = this;
    prev = &smartptr;
    smartptr.next = this;

    /* Here we "this"'s in the double linked reference list, thats look like
     *
     * smartptr.next (A) <----> smartptr <----> this <-----> (B) this.next
     */
}

template <typename T>
void SmartPointer2<T>::release()
{
    if (!prev || prev==this)
    {
        /* If previous reference is null or is this
         * then "this"'s the last reference to p
         * free it
         */
        delete p;
    }
    else {
        /* They are remaining references,
         * just get "this" out of the double linked list
         */
        prev->next = next;
        next->prev = prev;
        prev = next = 0;
    }
    p = 0;
}
