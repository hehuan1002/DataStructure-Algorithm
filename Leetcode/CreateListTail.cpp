
#include "stdafx.h"
#include <stdio.h>

//������ڵ�
typedef struct LNode
{
	int nData;
	struct LNode *next;
}LinKList;


// ָ������
void CreateListTail(LinKList *&list, int data[], int n)
{
	list = new LinKList;
	LinKList *r = list; // r�ڵ�һֱָ�������β��
	for (int i =0; i < 3; i++)
	{
		LinKList *node = new LinKList;
		node->nData = data[i];
		r->next = node;
		r = node;
	}

	r->next = NULL;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int data[3] = {1,2,3};
	LinKList *list = NULL;

	CreateListTail(list, data, sizeof(data)/sizeof(int));

	struct LNode *tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->nData);
		tempNode = tempNode->next;
	}

	printf("NULL\n");
	return 0;
}
