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

// ������δ����ϸ�������˵�������Ǳ�׼��ð�������㷨����Ϊ�������㡰�����Ƚ����ڼ�¼������ֻ������򵥵Ľ���������ѡ�
// sort˼·�Ƚϼ򵥣�������ÿһ���ؼ��֣������������ÿһ���ؼ��ֱȽϣ�������򽻻���������һλ�õĹؼ�������ϡѭ����һ�������Сֵ����i=0ʱ���Ͱ�r[0]����С��ֵ����i=1ʱ�Ͱ�r[1]�ŵڶ�С��ֵ��.....�������ơ�
void BubbleSort(Sqlist *L)
{
	for (int i = 0; i < L->length; i++)
	{
		for (int j = i+1; j< L->length; j++)
		{
			if (L->r[i] > L->r[j])
			{
				// ������
				printf("%d ", i);
				printf("%d %d ",L->r[i],L->r[j]);
				swap(L, i, j);
				printf("%d %d    ",L->r[i],L->r[j]);
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
	BubbleSort(&L);
	printf("�����");
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");
	return 0;
}