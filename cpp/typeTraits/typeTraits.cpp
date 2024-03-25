/*************************************************************************
    > File Name: typeTraits.cpp
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月25日 星期一 17时22分17秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include <string.h>
#include <typeinfo>
#include "typeTraits.h"

template<class _Tp>
struct TypeTraits
{
	typedef __FalseType __IsPODType;
};

template <>
struct TypeTraits< bool>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< char>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned char >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< short>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned short >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< int>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned int >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< long>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned long >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< long long >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned long long>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< float>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< double>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< long double >
{
	typedef __TrueType __IsPODType;
};

template <class _Tp>
struct TypeTraits< _Tp*>
{
	typedef __TrueType __IsPODType;
};

template<class T>
void Copy(const T* src, T* dst, size_t size, __FalseType)
{
	std::cout<<"__FalseType:" <<typeid(T).name()<<std::endl;
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
}

template<class T>
void _Copy(const T* src, T* dst, size_t size, __TrueType)
{
	std::cout<<"__TrueType:"<<typeid(T).name()<<std::endl;
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
}

template<class T>
void __Copy(const T* src, T* dst, size_t size)
{
	std::cout<<"__TrueType:" <<typeid(T).name ()<<std::endl;
	if(typename TypeTraits<T>::__IsPODType().Get())
	{
		memcpy(dst,src,size*sizeof(T));
	}
	else
	{
		for(size_t i =0; i < size; i++)
		{
			dst[i] = src[i];
		}
	}
}

void typeTraits_test1(void)
{
	std::string s1 [10] = {"1", "2", "3" , "4444444444444444444444444" };
	std::string s2 [10] = {"11", "22", "33" };
	Copy(s1, s2, 10, TypeTraits <std::string>::__IsPODType());
	__Copy(s1 , s2, 10);
	int a1[10] = {1,2,3};
	int a2[10] = {0};
	_Copy(a1, a2, 10, TypeTraits <int>::__IsPODType());
	__Copy(a1, a2, 10);
}
