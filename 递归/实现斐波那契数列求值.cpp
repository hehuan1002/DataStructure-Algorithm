//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

// 
// ��num=100ʱ���ǳ��ǳ���������Ϊ��̫����ظ����㡣
// TODO: ���Բ��õ������߿����ݼ��㣬�����������д���ɡ�[3/30/2019 hehuan]
int fab(int num)
{
	if (num < 2)
		return (num==0)?0:1;
	
	return fab(num-1)+fab(num-2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nResult = fab(5);
	printf("Result is :%d", nResult);
	return 0;
}