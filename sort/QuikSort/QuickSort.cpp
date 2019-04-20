#include "stdafx.h"


/*********************
   快速排序是对冒泡排序的一种改进。它的基本思想是，通过一趟排序将待排记录分割成独立的两个部分，其中一部分记录的关键字均比另一部分记录的
关键字小，则可分别对着两部分记录继续进行排序，以达到整个序列有序。
   假设待排序的序列为{L.r[s],L.r[s+1],......,L.r[t]}，首先任意选取一个记录（通常可选第一个记录L.r[s]）作为枢(shu)轴（或支点）(pivot)，
然后按下述原则重新排列其余记录；将所有关键字较它小的记录安置在它的位置之前，将所有关键字较它大的记录都安置在它的位置之后。由此可以该“枢轴”
记录最后所落的位置i作分界线，将序列{L.r[s],L.[r+1],.....L.r[t]}分割成两个子序列{L.r[s],L.r[s+1],...,L.r[i-1]}和{L.r[i+1],L.r[i+2],...,L.[t]}。
这个过程称做一趟快速排序（或一次划分）。
   一趟快速排序的具体做法是：附设两个指针low和high，他们的初值分别为low和high，设枢轴记录的关键字为pivotkey，则首先从high所指位置起向前搜索找到
第一个关键字小于pivotkey的记录和枢轴记录互相交换，然后从low所指位置起向后搜索，找到第一个关键字小于pivotkey的记录和枢轴记录互相交换，然后从low
所指位置起向后搜索，找到第一个关键字大于pivotkey的记录和枢轴记录互相交换，重复这两步直至low==high为止。
对所有排序而言，最外层的循环都是必须的，只是内层循环需要改变一下，所以快速排序的时间复杂度为O(nlogn)，空间复杂度为O(logn)。


********************/
#define MAXSIZE 9
typedef struct
{
	int r[MAXSIZE];
	int length;
}Sqlist;

void swap(Sqlist *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void Init(Sqlist *L)
{
	L->r[0] = 50;
	L->r[1] = 10;
	L->r[2] = 90;
	L->r[3] = 30;
	L->r[4] = 70;
	L->r[5] = 40;
	L->r[6] = 80;
	L->r[7] = 60;
	L->r[8] = 20;

	L->length = MAXSIZE;
}

int Partition(Sqlist& L, int low, int high)
{
	int Pivotkey = L.r[low]; // 下标对应的值
	while (low < high)
	{
		while (low < high && L.r[high] >= Pivotkey) --high;
		swap(&L, low, high);
		while (low < high && L.r[low] <= Pivotkey) ++low;
		swap(&L, low, high);
	}

	return low;
}

void QSort(Sqlist&L, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(L, low, high);
		QSort(L, low, pivot-1);// pivot是下标索引值
		QSort(L,pivot+1, high);
	}
}


void QuickSort(Sqlist &L)
{
	QSort(L, 0, L.length - 1);
}
int _tmain(int argc, _TCHAR* argv[]){
	
	Sqlist L;
	Init(&L);

	// 排序前
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");

	QuickSort(L);

	// 排序后
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");

	return 0;
}