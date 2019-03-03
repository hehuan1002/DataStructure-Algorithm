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

LinKList* MiddleNode2(LinKList* list)
{
	LinKList* p = list->next;
	std::vector<LinKList*> vec;
	if (p == NULL)
	{
		return NULL;
	}

	while (p)
	{
		vec.push_back(p);
		p = p->next;
	}

	return vec[vec.size()/2];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[1] = {1};
	LinKList *list = NULL;
	CreateListHead(list, data, sizeof(data)/sizeof(int));
	struct LNode *tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");

	LinKList* list3 = MiddleNode2(list);
	printf("MiddleNode:%d", list3->nData);
	return 0;
}

