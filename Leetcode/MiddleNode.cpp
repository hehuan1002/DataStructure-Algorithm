// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
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

//ָ������
void CreateListHead(LinKList *&list, int data[], int n)
{
	list = new LinKList;
	list->next = NULL; //���ȴ���һ��ͷ�ڵ㣬next��ֵΪNULL��
	for (int i = 0; i < n; i++)
	{
		LinKList *node = new LinKList;
		node->nData = data[i];

		node->next = list->next;
		list->next = node;
	}
}

LinKList* MiddleNode(LinKList* list)
{
	LinKList* fast = list->next;
	LinKList* slow = list->next;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[6] = {6,5,4,3,2,1};
	LinKList *list = NULL;

	CreateListHead(list, data, sizeof(data)/sizeof(int));
	struct LNode *tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");

	LinKList* list3 = MiddleNode(list);
	printf("MiddleNode:%d", list3->nData);
	return 0;
}

