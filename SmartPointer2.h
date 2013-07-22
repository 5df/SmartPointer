#ifndef SMARTPOINTER2_H
#define SMARTPOINTER2_H

template <typename T>
class SmartPointer2
{
    public:
        SmartPointer2(T *ptr);
        ~SmartPointer2();
        SmartPointer2(const SmartPointer2& o);
        SmartPointer2<T>& operator=(const SmartPointer2& o);
        T& operator*();
        T* operator->();
    private:
        T *p;
        mutable const SmartPointer2 *prev;
        mutable const SmartPointer2 *next;

        void acquire(const SmartPointer2& o);
        void release();
};
#endif // SMARTPOINTER2_H
