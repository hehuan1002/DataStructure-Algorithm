//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int fac(int num)
{
	if (num == 1)
	{
		return 1;
	}

	return num*fac(num-1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nResult = fac(10);
	printf("Result is :%d", nResult);
	return 0;
}