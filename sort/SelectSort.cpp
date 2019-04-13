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

// ѡ������Ķ��壺
// ����д������ [4/7/2019 hehuan]
void SelectSort(Sqlist *L)
{
	int i,j,min;
	for (i = 0; i < L->length; i++)
	{
		min = i;
		for (j = i+1; j < L->length; j++)
		{
			if (L->r[min] > L->r[j])
			{
				min = j;
			}
		}

		if (i != min)
		{
			// ������
			printf("%d ", i);
			printf("%d %d ",L->r[i],L->r[min]);
			swap(L, i, min);
			printf("%d %d    ",L->r[i],L->r[min]);
			for (int i = 0; i < L->length; i++){
				printf("%d ", L->r[i]);
			}
			printf("\n");
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
	SelectSort(&L);
	printf("�����");
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");

	return 0;
}