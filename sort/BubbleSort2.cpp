//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"

#define MAXSIZE 9
typedef struct  
{
	int r[MAXSIZE];
	int length;
}Sqlist;

void Init(Sqlist *L)
{
	L->r[0] = 9;
	L->r[1] = 1;
	L->r[2] = 5;
	L->r[3] = 8;
	L->r[4] = 3;
	L->r[5] = 7;
	L->r[6] = 4;
	L->r[7] = 6;
	L->r[8] = 2;
	
	L->length = MAXSIZE;
}

void swap(Sqlist *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// ð���㷨�Ķ������£�ð������һ�ֽ����������Ļ���˼���ǣ������Ƚ����ڼ�¼�Ĺؼ��֣���������򽻻���ֱ��û�з���ļ�¼Ϊֹ��
// ����for(int j = 0; j < L->length - i - 1; j--),��i�仯ʱ��jȡֵ��Χ��[0,8),[0,7),[0,6),[0,5),[0,4),[0,3),[0,2),[0,1),[0,0)
// ��i=0ʱ�����ֵ�Ѿ�����������ˣ����Ե�i=1ʱ��jֻ��Ҫ��0��7�ˣ��Դ����ơ�����
void BubbleSort2(Sqlist *L)
{
	for (int i = 0; i < L->length; i++)
	{
		int n = L->length - i -1;
		for (int j = 0; j < L->length - i - 1; j++)
		{
			if (L->r[j] > L->r[j+1])
			{
				// ������
				printf("%d ", i);
				printf("%d %d ",L->r[j],L->r[j+1]);
				swap(L, j, j+1);
				printf("%d %d    ",L->r[j],L->r[j+1]);
				for (int i = 0; i < L->length; i++){
					printf("%d ", L->r[i]);
				}
				printf("\n");
			}
		}
	}
}

// ����for(int j = 0; j < L->length - i - 1; j--),��i�仯ʱ��jȡֵ��Χ��[7,0],[7,1],[7,2],[7,3],[7,4],[7,5],[7,6],[7,7]
void BubbleSort2_(Sqlist *L)
{
	for (int i = 0; i < L->length; i++)
	{
		for (int j = L->length - 2; j >= i; j--)
		{
			if (L->r[j] > L->r[j+1])
			{
				// ������
				printf("%d ", i);
				printf("%d %d ",L->r[j],L->r[j+1]);
				swap(L, j, j+1);
				printf("%d %d    ",L->r[j],L->r[j+1]);
				for (int i = 0; i < L->length; i++){
					printf("%d ", L->r[i]);
				}
				printf("\n");
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[]){
	// ��ʼ��
	Sqlist L;
	Init(&L);
	printf("����ǰ��");
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");

	// �����
	BubbleSort2_(&L);
	printf("�����");
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");
	return 0;
}