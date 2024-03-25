/*************************************************************************
  > File Name: sharedPointer.cpp
  > Author: szl
  > Mail: shaozonglin321@163.com
  > Created Time: 2024年03月25日 星期一 16时54分39秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include "sharedPointer.h"

/*smart pointer demo*/
    template<typename T>
SmartPointer<T>::SmartPointer(T* ptr) 
    :_ptr(ptr) 
{
    if (_ptr) 
    {
        _count = new size_t(1);
    }
    else 
    {
        _count = new size_t(0);
    }
}

    template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer& ptr) 
{
    if (this != &ptr) 
    {
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
    }
}

    template<typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& ptr) 
{
    if (this->_ptr == ptr._ptr) 
    {
        return *this;
    }

    if (this->_ptr) 
    {
        (*this->_count)--;
        if (this->_count == 0) 
        {
            delete this->_ptr;
            delete this->_count;
        }
    }

    this->_ptr = ptr._ptr;
    this->_count = ptr._count;
    (*this->_count)++;
    return *this;
}

    template<typename T>
T& SmartPointer<T>::operator*() 
{
    assert(this->_ptr == nullptr);
    return *(this->_ptr);

}

    template<typename T>
T* SmartPointer<T>::operator->() 
{
    assert(this->_ptr == nullptr);
    return this->_ptr;
}

    template<typename T>
SmartPointer<T>::~SmartPointer() 
{
    (*this->_count)--;
    if (*this->_count == 0) 
    {
        delete this->_ptr;
        delete this->_count;
    }
}

    template<typename T>
size_t SmartPointer<T>::use_count()
{
    return *this->_count;
}

void SmartPointerDemo(void)
{
    SmartPointer<int> sp(new int(10));
    SmartPointer<int> sp2(sp);
    SmartPointer<int> sp3(new int(20));
    sp2 = sp3;
    std::cout << sp.use_count() << std::endl;
    std::cout << sp3.use_count() << std::endl;
}
