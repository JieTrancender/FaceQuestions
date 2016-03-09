/*************************************************************************
    > File Name: single_class_second.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar  4 19:44:37 2016
 ************************************************************************/

//问题描述:设计一个单例类

#include <iostream>

class SingleClass
{
private:
	SingleClass()
	{
		//为空
	}

public:
	~SingleClass()
	{
		std::cout << "destruct single class." << std::endl;
	}

	static SingleClass* get_instance()
	{
		static SingleClass instance;
		return &instance;
	}
};

int main(int argc, char** argv)
{
	SingleClass *single_first = SingleClass::get_instance();
	SingleClass *single_second = single_first;
	SingleClass *single_third = SingleClass::get_instance();
	std::cout << single_first << std::endl;
	std::cout << single_second << std::endl;
	std::cout << single_third << std::endl;

	return 0;
}
