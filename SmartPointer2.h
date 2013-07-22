#ifndef SMARTPOINTER2_H
#define SMARTPOINTER2_H

/*!
 * SmartPointer2
 * \brief A smart pointer based on a reference linking.
 */

template <typename T>
class SmartPointer2
{
    public:
        /*!
         * Consructor
         * \brief Initialize a new smart pointer
         * \param ptr An existing pointer to a USER ALLOCATED memory
         */
        SmartPointer2(T *ptr);

        /*!
         * Destructor
         * \brief Delete reference to the pointer and delete it if no reference left
         */
        ~SmartPointer2();

        /*!
         * Copy constructor
         * \brief Initialize from an existing smart pointer
         * \param smartptr An existing smart pointer
         */
        SmartPointer2(const SmartPointer2& smartptr);

        /*!
         * Indirection operator
         * \return A reference to the object pointed by the wrapped pointer
         */
        T& operator*();

        /*!
         * Structure dereference operator
         * \return The wrapped pointer itself
         */
        T* operator->();

        /*!
         * Assignement operator
         * \param smartptr An existing SmartPointer instance
         * \return A freshly initialized SmartPointer
         */
        SmartPointer2<T>& operator=(const SmartPointer2& smartptr);
    private:
        /*
         * The wrapped pointer
         */
        T *p;
        /*
         * The previous an next reference to the pointer
         */
        mutable const SmartPointer2 *prev;
        mutable const SmartPointer2 *next;

        /*
         * Add "this" reference to the pointer
         */
        void acquire(const SmartPointer2& o);
        /*
         * Release "this" reference to the pointer and delete it if no reference left
         */
        void release();
};
#endif // SMARTPOINTER2_H
