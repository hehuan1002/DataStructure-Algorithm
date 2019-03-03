// TestReverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

typedef struct LNode
{
	int nData;
	struct LNode *next;
}LinKList;

//创建循环列表
void CreateCycleListTail(LinKList *&list, int data[], int n)
{
	list = new LinKList;
	list->nData = -1;
	list->next = list; 
	LinKList*r = list;
	for (int i = 0; i < n; i++)
	{
		LinKList *node = new LinKList;
		node->nData = data[i];
		node->next = r->next;
		r->next = node;
		r = node;
	}
}

bool CheckCircle(LinKList *list)
{
	if (list == NULL)
		return false;
	
	LinKList* fast = list;
	LinKList* slow = list;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[3] = {3,2,1};
	LinKList *list = NULL;
	CreateCycleListTail(list, data, sizeof(data)/sizeof(int));

	LinKList* head = list;
	LinKList* tempNode = list;
	while (1)
	{
		printf("%d->", tempNode->nData);
		if (tempNode->next == head)
			break;
		tempNode = tempNode->next;
	}
	printf("%d\n",head->nData);

	bool result = CheckCircle(list);
	return 0;
}

