/*************************************************************************
    > File Name: is_post_traverse.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: 2016年03月02日 星期三 14时54分20秒
 ************************************************************************/

//题目描述：给定一个序列，判断序列是否是二元查找树
//二元查找树：本身是一颗二元树，且如果子树不为空，左子树都小于根节点，右子树都大于根节点并且所有的子树都是二元查找树

#include <iostream>
#include <cstdlib>

int is_post_traverse(int* arr, int len)
{
	int *head, *pos, *p;
	if(arr == nullptr || len <= 0)
		return 0;
	if(len == 1)
		return 1;
	
	head = arr + len - 1;
	p = arr;

	while(*p < *head)
		++p;
	pos = p;
	while(p < head)
	{
		if(*p < *head)
			return 0;
		++p;
	}

	if(!is_post_traverse(arr, pos - arr))
		return 0;
	return is_post_traverse(pos, head - pos);
}

int main(int argc, char** argv)
{
	int *arr = new int[argc];
	for(int i = 1; i < argc; ++i)
		arr[i - 1] = atoi(argv[i]);
	for(int i = 0; i < argc - 1; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	if(is_post_traverse(arr, argc - 1))
		std::cout << "This is post traverse." << std::endl;
	else
		std::cout << "This is not post traverse." << std::endl;
	return 0;
}
