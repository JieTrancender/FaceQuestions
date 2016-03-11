/*************************************************************************
    > File Name: is_palindrome.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar 11 17:21:05 2016
 ************************************************************************/

//题目描述：给定一个字符串，判断该串是不是回文串
//例如："abcba" -> true

#include <iostream>
#include <cstring>

bool is_palindrome(const char* str, int n)
{
	if(str == nullptr || n < 1)
		return false;

	const char *front, *back;

	//初始化头指针
	front = str;
	back = str + n -1;

	while(front < back)
	{
		if(*front != *back)
			return false;
		++front;
		--back;
	}
	return true;
}

int main(int argc, char** argv)
{

	const char str[] = "iamastrrtsamai";
	std::cout << is_palindrome(str, strlen(str)) << std::endl;
	return 0;
}
