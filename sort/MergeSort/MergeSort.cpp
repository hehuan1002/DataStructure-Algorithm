#include "stdafx.h"
#include <vector>


/*********************
�鲢��������һ�಻ͬ�����򷽷������鲢���ĺ����ǽ��������������ϵ��������ϳ�һ���µ����������ʵ�ַ�������Ϊ��������Ϥ��������˳��洢�ṹ
��������洢�ṹ��������O(m+n)��ʱ��������ʵ�֡����ù鲢��˼������ʵ�����򡣼����ʼ���к���n����¼����ɿ�����n������������У�ÿ�������е�
����Ϊ1��Ȼ�������ϲ����õ�[n/2]������Ϊ2��1�����������У��������鲢��......������ظ��������õ�һ������Ϊn����������Ϊֹ���������򷽷���Ϊ
2-·�鲢����

******************/

/************************************************************************/
/* �ϲ�����Ϊ���������벿�ֵ��ڲ�����
aΪ��������
tmpArrayΪ���ù鲢���������
leftPosΪ����������Ԫ�ص��±�
rightPosΪ��벿�������±�
rightEndΪ����������Ԫ�ص��±�
*/
/************************************************************************/
void Merge(std::vector<int> &a, std::vector<int> &tmpArray, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElemets = rightEnd - leftPos + 1;

	//��ѭ��
	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (a[leftPos] <= a[rightPos])
			tmpArray[tmpPos++] = std::move(a[leftPos++]);
		else
			tmpArray[tmpPos++] = std::move(a[rightPos++]);
	}

	// ��ֵǰ�벿�ֵ�ʣ��Ԫ��
	while (leftPos <= leftEnd)
		tmpArray[tmpPos++] = std::move(a[leftPos++]);

	// ��ֵ��벿�ֵ�ʣ��Ԫ��
	while (rightPos <= rightEnd)
		tmpArray[tmpPos++] = std::move(a[rightPos++]);

	// ��tmpArray��ֵ��ԭ����a
	for (int i =0; i < numElemets; ++i, --rightEnd)
		a[rightEnd] = std::move(tmpArray[rightEnd]);
}


/************************************************************************/
/*���еݹ���õ��ڲ�����
 aΪ����
 tmpArrayΪ���ù鲢���������
 leftΪ����������Ԫ�ص��±�
 rightΪ����������Ԫ�ص��±�
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
/*�鲢�����㷨����������                                              
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