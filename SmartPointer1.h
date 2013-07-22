#ifndef SMARTPOINTER1_H
#define SMARTPOINTER1_H

template <typename T>
class SmartPointer1
{
    public:
        SmartPointer1(T*);
        virtual ~SmartPointer1();
        SmartPointer1(const SmartPointer1<T>&);
        T* operator->();
        T& operator* ();
        SmartPointer1<T>& operator=(const SmartPointer1<T>&);
    private:
        struct Counter{
            Counter(T* ptr, unsigned int c): p(ptr), count(c){}
            T *p;
            unsigned int count;
        }*counter;

        void acquire(Counter*);

        void release();
};

#endif // SMARTPOINTER1_H
