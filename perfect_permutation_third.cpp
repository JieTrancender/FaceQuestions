/*************************************************************************
    > File Name: perfect_permutation_third.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Sat Mar 12 13:15:21 2016
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

int main(int argc, char **argv)
{
	int num[] = {
		1, 2, 3, 4, 5
	};
	std::sort(num, num + sizeof(num) / sizeof(num[0]));

	do
	{
		std::copy(num, num + sizeof(num) / sizeof(num[0]), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}while(std::next_permutation(num, num + sizeof(num) / sizeof(num[0])));
	return 0;
}
