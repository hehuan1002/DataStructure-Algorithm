// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

typedef struct LNode
{
	int nData;
	struct LNode *next;
}LinKList;

//����ѭ���б�
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
	return 0;
}

