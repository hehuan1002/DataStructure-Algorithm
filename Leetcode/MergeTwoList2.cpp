// TestReverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>
#include <vector>
using namespace std;

typedef struct LNode
{
	int nData;
	struct LNode *next;
}LinKList;

//指针引用
void CreateListHead(LinKList *&list, int data[], int n)
{
	list = new LinKList;
	list->next = NULL; //首先创建一个头节点，next赋值为NULL。
	for (int i = 0; i < n; i++)
	{
		LinKList *node = new LinKList;
		node->nData = data[i];

		node->next = list->next;
		list->next = node;
	}
}

LinKList* MergeTwoList2(LinKList* list, LinKList * list2)
{
	if (list == NULL)
	{
		return list2;
	}
	else if (list2 == NULL)
	{
		return list;
	}
	else 
	{
		if (list->nData <= list2->nData)
		{
			LinKList *p = MergeTwoList2(list->next, list2);
			list->next = p;
			return list;
		}
		else
		{
			LinKList *p = MergeTwoList2(list, list2->next);
			list2->next = p;
			return list2;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[3] = {3,2,1};
	LinKList *list = NULL;

	CreateListHead(list, data, sizeof(data)/sizeof(int));
	struct LNode *tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");

	int data2[3] = {6,5,4};
	LinKList *list2 = NULL;
	CreateListHead(list2, data2, sizeof(data2)/sizeof(int));
	tempNode = list2->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");


	LinKList* list3 = MergeTwoList2(list->next, list2->next);
	tempNode = list3;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");
	return 0;
}

