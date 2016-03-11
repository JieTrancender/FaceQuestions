/*************************************************************************
    > File Name: perfect_permutation_second.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar 11 13:06:14 2016
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>

bool perfect_permutation(char* perm, int num)
{
	int i;
	//找到排列在最后一个升序的首位位置i,x = perm[i]
	for(i = num - 2; (i >= 0 && (perm[i] >= perm[i + 1])); --i)
	{
		;//空语句
	}

	//不满足升序条件
	if(i < 0)
		return false;

	int j;
	//找到排列中第i位右边最后一个比x打的位置j,y = perm[j]
	for(j = num - 1; (j > i && perm[j] <= perm[i]); --j)
	{
		;//空语句
	}

	//交换x和y
	std::swap(perm[i], perm[j]);

	//翻转i后面的元素
	std::reverse(perm + i + 1, perm + num);
	return true;
}

int main(int argc, char** argv)
{
	char str[] = "123456";
	int count = 1;
	
	std::cout << count << ":" << str << std::endl;

	while(strcmp(str, "654321") < 0)
	{
		perfect_permutation(str, strlen(str));
		std::cout << ++count << ":" << str << std::endl;
	}

	return 0;
}
