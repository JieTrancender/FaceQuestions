/*************************************************************************
    > File Name: not_inherit_class.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar  4 16:37:35 2016
 ************************************************************************/

//描述:设计一个不可以被继承的class

//预备知识:当类的构造函数和析构函数都是私有的时候就不能被继承,并且友元类可以访问类的私有函数或者变量

#include <iostream>

template <typename anytype>
class BaseClass
{
	friend anytype;
private:
	BaseClass()
	{
		std::cout << "Construct base class." << std::endl;  
	}

	~BaseClass()
	{
		std::cout << "Destruct base class." << std::endl;
	}
};

class WorkClass : virtual public BaseClass<WorkClass>
{
public:
	WorkClass()
	{
		std::cout << "Construct work class." << std::endl;
	}

	~WorkClass()
	{
		std::cout << "Destruct work class." << std::endl;
	}
};

/*
class TestClass : public WorkClass
{
public:
	TestClass()
	{
		std::cout << "Construct test class." << std::endl;
	}

	~TestClass()
	{

		std::cout << "Destruct test class." << std::endl;
	}
};
*/

int main(int argc, char** argv)
{
	WorkClass work_object;
	//TestClass test_object;
	return 0;
}

//问题来源:通常我们构造类时只初始化自己的直接基类,但是在虚继承的时候可能导致虚基类被多次初始化,为了解决这一问题,得从具有虚基类继承的类在初始化时进行特殊处理,在虚派生中,由最低层次的类的构造函数初始化虚基类
