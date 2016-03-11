/*************************************************************************
    > File Name: longest_palindrome_first.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: 2016年03月11日 星期五 21时42分53秒
 ************************************************************************/

//题目描述：给定一个字符串，求他的最长回文字串的长度
//中心扩展法:枚举所有的中心位置，然后再在该位置上扩展，记录并更新得到的最长回文串的长度

#include <iostream>
#include <cstring>

int longest_palindrome(const char* str, int n)
{
	int i, j, max, c;
	if(str == nullptr || n < 1)
		return 0;

	max = 0;

	//i为回文的中心位置
	for(i = 0; i < n; ++i)
	{
		//回文长度为奇数
		for(j = 0; (i - j >= 0) && (i + j < n); ++j)
		{
			if(str[i - j] != str[i + j])
				break;
			c = j * 2 + 1;
		}
		if (c > max)
			max = c;

		//回文长度为偶数
		for(j = 0; (i - j >= 0) && (i + j + 1 < n); ++j)
		{
			if(str[i - j] != str[i + j + 1])
				break;
			c = j * 2 + 2;
		}
		if(c > max)
			max = c;
	}
	return max;
}

int main(int argc, char** argv)
{
	const char str_first[] = "mynameismojieeijomsi";
	const char str_second[] = "12345654321";

	std::cout << str_first << ": " << longest_palindrome(str_first, strlen(str_first)) << std::endl;
	std::cout << str_second << ": " << longest_palindrome(str_second, strlen(str_second)) << std::endl;
}
