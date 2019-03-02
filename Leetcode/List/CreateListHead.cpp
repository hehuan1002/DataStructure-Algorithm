#include "stdafx.h"
#include <stdio.h>

//�������ڵ�
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
	return 0;
}
