//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 
// 当num=100时，非常非常的慢，因为有太多的重复计算。
// TODO: 可以采用迭代或者快速幂计算，这两个方法有待完成。[3/30/2019 hehuan]
int Fbi(int num)
{
	if (num < 2)
		return (num==0)?0:1;
	
	return Fbi(num-1)+Fbi(num-2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nResult = Fbi(5);
	printf("Result is :%d", nResult);
	return 0;
}