/*************************************************************************
    > File Name: string_to_int.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar 11 16:51:35 2016
 ************************************************************************/

//题目描述：输入一个由数字组成的字符串，将它转换成整数并输出，不能使用库函数atoi
//举例:"123" -> 123

#include <iostream>

int string_to_int(const char* str)
{
	static const int MAX_INT = (int)((unsigned)~0 >> 1);
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
	unsigned int n = 0;

	//判读输入是否为空
	if(str == nullptr)
		return 0;

	//处理空格
	while(isspace(*str))
		++str;

	//处理正负
	int sign = 1;
	if(*str == '+' || *str == '-')
	{
		if(*str == '-')
			sign = -1;
		++str;
	}

	//确认是数字后执行循环
	while(isdigit(*str))
	{
		//处理溢出
		int c = *str - '0';
		if(sign > 0 && (n > MAX_INT / 10) || (n == MAX_INT / 10 && c > MAX_INT % 10))
		{
			n = MAX_INT;
			break;
		}
		else if(sign < 0 && (n > (unsigned)MIN_INT / 10 || (n == MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
		{
			n = MIN_INT;
			break;
		}

		//把之前得到的数字乘以10，再加上当前字符表示的数字
		n = n * 10 + c;
		++str;
	}
	return sign > 0 ? n : -n;
}

int main(int argc, char** argv)
{
	char str[] = "-234232";
	std::cout << string_to_int(str) << std::endl;
	return 0;
}
