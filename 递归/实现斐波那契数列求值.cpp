//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

// 
// ��num=100ʱ���ǳ��ǳ���������Ϊ��̫����ظ����㡣
// TODO: ���Բ��õ������߿����ݼ��㣬�����������д���ɡ�[3/30/2019 hehuan]
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