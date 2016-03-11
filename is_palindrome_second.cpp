/*************************************************************************
    > File Name: is_palidrome_second.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar 11 17:27:30 2016
 ************************************************************************/

#include <iostream>
#include <cstring>

bool is_palindrome(const char* str, int n)
{
	if(str == nullptr || n < 1)
		return false;

	const char *front, *back;

	//m定位到字符串的中间
	int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0;
	front = str + m;
	back = str + n - m - 1;

	while(front >= str)
	{
		if(*front != *back)
			return false;
		--front;
		++back;
	}
	return true;
}

int main(int argc, char** argv)
{
	const char strstr[] = "abcdefedcba";
	std::cout << is_palindrome(strstr, strlen(strstr)) << std::endl;
	return 0;
}
