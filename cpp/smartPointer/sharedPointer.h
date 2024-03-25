/*************************************************************************
    > File Name: sharedPointer.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月25日 星期一 16时54分36秒
 ************************************************************************/

#ifndef _SHAREDPOINTER_H
#define _SHAREDPOINTER_H

/*smart pointer demo*/
template<typename T>
class SmartPointer 
{
private:
    T* _ptr;
    size_t* _count;
public:
    SmartPointer(T* ptr = nullptr);

    SmartPointer(const SmartPointer& ptr);

    SmartPointer& operator=(const SmartPointer& ptr);

    T& operator*();

    T* operator->();

    ~SmartPointer();
	
    size_t use_count();
};

void SmartPointerDemo(void);

#endif
