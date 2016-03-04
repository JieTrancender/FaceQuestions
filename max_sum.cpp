/*************************************************************************
    > File Name: max_sum.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: 2016年03月02日 星期三 14时45分33秒
 ************************************************************************/

//题目描述:给定一个序列,就子序列中的最大值
//例如:1 -2 3 10 -4 7 2 -5 最大子序列为 3 10 -4 7 2 即 18

#include <iostream>

int max_sum(int* arr, int n)
{
	int sum = 0, max = 0;
	for(int i = 0; i < n; ++i)
	{
		if(sum < 0)
			sum = arr[i];
		else
			sum += arr[i];
		if(sum > max)
			max = sum;
	}
	return max;
}

int main(int argc, char **argv)
{
	int arr[] = {
		1, -2, 3, 10, -4, 7, 2, -5
	};
	std::cout << "max: " << max_sum(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;
	return 0;
}
