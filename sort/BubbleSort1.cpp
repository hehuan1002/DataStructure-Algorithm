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

// 下面这段代码严格意义来说，不算是标准的冒泡排序算法，因为它不满足“两两比较相邻记录”，而只是最最简单的交换排序而已。
// sort思路比较简单，就是让每一个关键字，都和它后面的每一个关键字比较，如果大则交换，这样第一位置的关键字在依稀循环后一定变成最小值。当i=0时，就把r[0]放最小的值，当i=1时就把r[1]放第二小的值，.....依次类推。
void BubbleSort(Sqlist *L)
{
	for (int i = 0; i < L->length; i++)
	{
		for (int j = i+1; j< L->length; j++)
		{
			if (L->r[i] > L->r[j])
			{
				// 排序中
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
	// 初始化
	Sqlist L;
	Init(&L);
	printf("排序前：");
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");

	// 排序后
	BubbleSort(&L);
	printf("排序后：");
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");
	return 0;
}