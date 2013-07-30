#define BOOST_TEST_MODULE test_smart_pointer
#include <boost/test/unit_test.hpp>

#include "SmartPointer1.cpp"

template <typename T>
T test1(T* pval)
{
  SmartPointer1<T> sp1(pval);
  return *sp1;
}

template <typename T>
void subroutine1(SmartPointer1<T>& sp1)
{
    // do some stuff with sp1
}


template <typename T>
T *test2(T val)
{
    T *pval = new T(val);
    test1(pval);
    return pval; 
}


BOOST_AUTO_TEST_CASE(init_test)
{
  BOOST_CHECK(5==test1(new int(5)));
}

BOOST_AUTO_TEST_CASE(free_test)
{
    BOOST_CHECK(nullptr==test2(5));
}
