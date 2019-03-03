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
	LinKList* p1 = list;
	LinKList* p2 = list2;

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

LinKList* MergeKList(std::vector<LinKList*> &vecLinkList)
{
	if (vecLinkList.empty())
		return NULL;

	if (vecLinkList.size() == 1)
		return vecLinkList[0];

	LinKList* p = vecLinkList[0];
	for (int i = 1; i < vecLinkList.size(); i++)
	{
		p= MergeTwoList(p, vecLinkList[i]);
	}

	return p;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int data[2] = {2,1};
	LinKList *list = NULL;
	CreateListHead(list, data, sizeof(data)/sizeof(int));
	struct LNode *tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");

	int data2[1] = {2};
	LinKList *list2 = NULL;
	CreateListHead(list2, data2, sizeof(data2)/sizeof(int));
	tempNode = list2->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");

	int data3[1] = {3};
	LinKList *list3 = NULL;
	CreateListHead(list3, data3, sizeof(data3)/sizeof(int));
	tempNode = list3->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");


	std::vector<LinKList *> vec;
	vec.push_back(list->next);
	vec.push_back(list2->next);
	vec.push_back(list3->next);
	LinKList* result = MergeKList(vec);
	tempNode = result;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");
	return 0;
}

