#include "stdafx.h"
#include <vector>


/*********************
归并排序是又一类不同的排序方法。“归并”的含义是讲两个或两个以上的有序表组合成一个新的有序表。它的实现方法早已为读者所熟悉，无论是顺序存储结构
还是链表存储结构，都可在O(m+n)的时间量级上实现。利用归并的思想容易实现排序。假设初始序列含有n个记录，则可看成是n个有序的子序列，每个子序列的
长度为1，然后两两合并，得到[n/2]个长度为2或1的有序子序列；再两两归并，......，如此重复，甚至得到一个长度为n的有序序列为止，这种排序方法称为
2-路归并排序。

******************/

/************************************************************************/
/* 合并数组为已排序两半部分的内部方法
a为输入数组
tmpArray为放置归并结果的数组
leftPos为子数组最左元素的下标
rightPos为后半部分起点的下标
rightEnd为子数组最右元素的下标
*/
/************************************************************************/
void Merge(std::vector<int> &a, std::vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElemets = rightEnd - leftPos + 1;

	//主循环
	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (a[leftPos] <= a[rightPos])
			tmpArray[tmpPos++] = std::move(a[leftPos++]);
		else
			tmpArray[tmpPos++] = std::move(a[rightPos++]);
	}

	// 赋值前半部分的剩余元素
	while (leftPos <= leftEnd)
		tmpArray[tmpPos++] = std::move(a[leftPos++]);

	// 赋值后半部分的剩余元素
	while (rightPos <= rightEnd)
		tmpArray[tmpPos++] = std::move(a[rightPos++]);

	// 将tmpArray赋值回原数组a
	for (int i =0; i < numElemets; ++i, --rightEnd)
		a[rightEnd] = std::move(tmpArray[rightEnd]);
}


/************************************************************************/
/*进行递归调用的内部方法
 a为数组
 tmpArray为放置归并结果的数组
 left为子数组最左元素的下标
 right为子数组最右元素的下标
*/
/************************************************************************/
void MergeSort(std::vector<int> &a, std::vector<int> &tmpArray, int left, int right)
{
	if (left < right)
	{
		int center = (left + right)/2;
		MergeSort(a, tmpArray, left, center);
		MergeSort(a, tmpArray, center+1, right);
		Merge(a, tmpArray, left, center+1, right);
	}
}


/************************************************************************/
/*归并排序算法（驱动程序）                                              
*/
/************************************************************************/
void MergeSort(std::vector<int> &a)
{
	std::vector<int> temArray(a.size());
	MergeSort(a, temArray, 0, a.size() - 1);
}



int _tmain(int argc, _TCHAR* argv[]){
	
	std::vector<int> a;
	a.push_back(16);
	a.push_back(7);
	a.push_back(13);
	a.push_back(10);
	
	MergeSort(a);

	return 0;
}