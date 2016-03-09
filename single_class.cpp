/*************************************************************************
    > File Name: single_class.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar  4 18:16:59 2016
 ************************************************************************/

//题目描述:只能拥有一个类对象,即单例模式

#include <iostream>

class SingleClass
{
private:
	SingleClass()
	{
		std::cout << "Construct single class." << std::endl;
	}

	~SingleClass()
	{
		std::cout << "Destruct single class." << std::endl;
		ptr_instance = nullptr;
	}

	static SingleClass *ptr_instance;

public:
	static SingleClass* get_instance()
	{
		if(ptr_instance == nullptr)
		{
			ptr_instance = new SingleClass();
		}
		return ptr_instance;
	}

	static void destory_instance()
	{
		if(ptr_instance != nullptr)
		{
			delete ptr_instance;
		}
	}
};

SingleClass *SingleClass::ptr_instance  = nullptr;

int main(int argc, char** argv)
{
	SingleClass *single_object = SingleClass::get_instance();
	std::cout << single_object << std::endl;

	SingleClass *single_object_second = SingleClass::get_instance();
	std::cout << single_object_second << std::endl;

	SingleClass *single_object_third = single_object;
	std::cout << single_object_third << std::endl;

	SingleClass::destory_instance();
	return 0;
}
