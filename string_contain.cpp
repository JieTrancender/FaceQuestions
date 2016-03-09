/*************************************************************************
    > File Name: string_contain_first.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Wed Mar  9 14:24:30 2016
 ************************************************************************/

//题目描述：给定一个字符串a，判断字符串b中的字符是否都属于字符串a(为了简单规定字符串只有大写字母)

//例如："adbfsdf"  "fsdf" -> true

#include <iostream>
#include <string>
#include <algorithm>

//方法一：暴力解决
bool string_contain_first(std::string &a, std::string &b)
{
	for(int i = 0; i < b.length(); ++i)
	{
		int j = 0;
		for(; j < a.length(); ++j)
		{
			if(a[j] == b[i])
				break;
		}
		if(j >= a.length())
			return false;
	}
	return true;
}

//方法二：排序后遍历判断
bool string_contain_second(std::string &a, std::string &b)
{
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	for(int pa = 0, pb = 0; pb < b.length();)
	{
		while(pa < a.length() && a[pa] < b[pb])
			++pa;
		if(pa >= a.length() || a[pa] > b[pb])
			return false;
		++pb;
	}
	return true;
}

//方法三：素数相乘法(由于数据太大，会超出long long的范围，所以此法不可行)
bool string_contain_third(std::string &a, std::string &b)
{
	const int symbol[26] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
	};

	int sum = 1;
	for(int i = 0; i < a.length(); ++i)
	{
		int x = symbol[a[i] - 'A'];
		if(sum % x)
			sum *= x;
	}
	for(int i = 0; i < b.length(); ++i)
	{
		int x = symbol[b[i] - 'A'];
		if(sum % x)
			return false;
	}
	return true;
}

//方法四:位运算法
bool string_contain_fourth(std::string &a, std::string &b)
{
	int hash = 0;
	for(int i = 0; i < a.length(); ++i)
	{
		hash |= (1 << (a[i] - 'A'));
	}
	for(int i = 0; i < b.length(); ++i)
	{
		if((hash & (1 << (b[i] - 'A'))) == 0)
			return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	std::string str_a = "ABCDEFGHIJKLMN";
	std::string str_b = "DEFGZ";
	
	if(string_contain_first(str_a, str_b))
		std::cout << "first: true" << std::endl;
	else
		std::cout << "first: false" << std::endl;

	if(string_contain_second(str_a, str_b))
		std::cout << "second: true" << std::endl;
	else
		std::cout << "second: false" << std::endl;

	//if(string_contain_third(str_a, str_b))
	//	std::cout << "third: true" << std::endl;
	//else
	//	std::cout << "third: false" << std::endl;

	if(string_contain_fourth(str_a, str_b))
		std::cout << "fourth: true" << std::endl;
	else
		std::cout << "fourth: false" << std::endl;
	return 0;
}
