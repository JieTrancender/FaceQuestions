/*************************************************************************
    > File Name: perfect_permutation.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Wed Mar  9 15:26:47 2016
 ************************************************************************/

//题目描述:给定一个字符串,输出他的全排列
//举例: "abc" -> "acb" "bac" "bca" "cab" "cba"

#include <iostream>
#include <algorithm>
#include <cstring>

void perfect_permutation(char *perm, int from, int to)
{
	if(to <= 1)
		return;
	if(from == to)
	{
		for(int i = 0; i <= to; ++i)
			std::cout << perm[i];
		std::cout << std::endl;
	}
	else
	{
		for(int j = from; j <= to; ++j)
		{
			std::swap(perm[from], perm[j]);
			perfect_permutation(perm, from + 1, to);
			std::swap(perm[from], perm[j]);
		}
	}
}

int main(int argc, char** argv)
{
	char str[] = "abc";
	perfect_permutation(str, 1, strlen(str) - 1);
	return 0;
}
