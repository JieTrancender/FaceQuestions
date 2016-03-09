/*************************************************************************
    > File Name: only_create_in_stack.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar  4 19:09:29 2016
 ************************************************************************/

//问题描述:设计一个类,使只能在堆上面创建对象

//知识点:因为在堆上面创建对象用的是new和delete,所以只要将这两个运算符设置为私有的时候就只能在栈上面创建对象了.

#include <iostream>

class StackClass
{
private:
	void* operator new(size_t size)
	{
		//为空
	}

	void operator delete(void* ptr)
	{
		//为空
	}

public:
	StackClass()
	{
		//为空
	}

	~StackClass()
	{
		//为空
	}
};
