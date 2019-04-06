//// TestMemset.cpp : 定义控制台应用程序的入口点。
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

// 冒泡算法的定义如下：冒泡排序一种交换排序，它的基本思想是：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止。
// 对于for(int j = 0; j < L->length - i - 1; j--),当i变化时，j取值范围有[0,8),[0,7),[0,6),[0,5),[0,4),[0,3),[0,2),[0,1),[0,0)
// 当i=0时，最大值已经到了最底下了，所以当i=1时，j只需要从0到7了，以此类推···
void BubbleSort2(Sqlist *L)
{
	for (int i = 0; i < L->length; i++)
	{
		int n = L->length - i -1;
		for (int j = 0; j < L->length - i - 1; j++)
		{
			if (L->r[j] > L->r[j+1])
			{
				// 排序中
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

// 对于for(int j = 0; j < L->length - i - 1; j--),当i变化时，j取值范围有[7,0],[7,1],[7,2],[7,3],[7,4],[7,5],[7,6],[7,7]
void BubbleSort2_(Sqlist *L)
{
	for (int i = 0; i < L->length; i++)
	{
		for (int j = L->length - 2; j >= i; j--)
		{
			if (L->r[j] > L->r[j+1])
			{
				// 排序中
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
	// 初始化
	Sqlist L;
	Init(&L);
	printf("排序前：");
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");

	// 排序后
	BubbleSort2_(&L);
	printf("排序后：");
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");
	return 0;
}