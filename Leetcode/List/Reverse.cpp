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

// TODO: ������ת�����⣿�� [3/2/2019 hehuan]
void Reverse(LinKList *&list)
{
	LinKList *p, *q;
	p = list->next;
	list->next = NULL;
	while (NULL != p)
	{
		q = p->next;
		p->next = list->next;
		list->next = q;
		p = q;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[3] = {1,2,3};
	LinKList *list = NULL;

	CreateListHead(list, data, sizeof(data)/sizeof(int));
	struct LNode *tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");


	Reverse(list);

	tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}
	printf("NULL\n");
	return 0;
}

