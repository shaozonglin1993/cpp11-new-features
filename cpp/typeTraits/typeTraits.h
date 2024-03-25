/*************************************************************************
    > File Name: typeTraits.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月25日 星期一 17时22分11秒
 ************************************************************************/

#ifndef _TYPETRAITS_H
#define _TYPETRAITS_H

struct __TrueType
{
	bool Get()
	{
		return true ;
	}
};

struct __FalseType
{
	bool Get()
	{
		return false ;
	}
};
//
// 使用参数推到的萃取处理
//
template<class T>
void Copy(const T* src, T* dst, size_t size, __FalseType);

template<class T>
void _Copy(const T* src, T* dst, size_t size, __TrueType);

//
// 使用萃取判断类型的Get函数判断是否是POD类型来处理
//
template<class T>
void __Copy(const T* src, T* dst, size_t size);

/*Test Case*/
void typeTraits_test1(void);


#endif
