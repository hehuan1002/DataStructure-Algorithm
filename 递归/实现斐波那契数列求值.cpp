//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 当num=100时，非常非常的慢，因为有太多的重复计算。
// TODO: 可以采用迭代或者快速幂计算，这两个方法有待完成。[3/30/2019 hehuan]
int fab(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else if (num == 1)
	{
		return 1;
	}
	else
	{
		return fab(num-1)+fab(num-2);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nResult = fab(5);
	printf("Result is :%d", nResult);
	return 0;
}