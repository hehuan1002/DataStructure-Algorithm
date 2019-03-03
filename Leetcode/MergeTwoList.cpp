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

LinKList* MergeTwoList(LinKList* list, LinKList * list2)
{
	LinKList* p1 = list->next;
	LinKList* p2 = list2->next;

	//LinKList* p = (LinKList*)malloc(sizeof(LinKList)); p = p->next;// 这种做法有问题,切记切记。
	LinKList* L  = (LinKList*)malloc(sizeof(LinKList));
	LinKList* r = L;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->nData <= p2->nData)
		{
			r->next = p1;
			p1 = p1->next;
		}
		else
		{
			r->next = p2;
			p2 = p2->next;
		}

		r = r->next; 
	}

	if (p1 != NULL)
	{
		r->next = p1;
	}

	if (p2 != NULL)
	{
		r->next = p2;
	}

	LinKList* p = L->next;
	free(L);
	return p;
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


	LinKList* list3 = MergeTwoList(list, list2);
	tempNode = list3;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");
	return 0;
}

