/*************************************************************************
    > File Name: string_reverse.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Wed Mar  2 15:29:13 2016
 ************************************************************************/

//题目描述：给定一个字符串，对字符串进行翻转操作
//例如：i am a student.  ->   .student a am i

#include <iostream>

void string_reverse(char* str, int begin, int end)
{
	while(begin < end)
	{
		char temp = str[begin];
		str[begin++] = str[end];
		str[end--] = temp;
	}
}

//str -> string
//n -> number
//m -> location
void string_convert(char* str, int n)
{
	//若要左移动大于n位,那么与%n是等价的
	string_reverse(str, 2, 3);
	string_reverse(str, 7, 14);
	string_reverse(str, 0, n - 1);
}

int main(int argc, char** argv)
{
	char str[] = "i am a student.";
	std::cout << str << std::endl;
	string_convert(str, 15);
	std::cout << str << std::endl;
	return 0;
}
