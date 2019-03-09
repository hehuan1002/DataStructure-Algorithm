// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkCycleList;



//����ѭ���б�, β�巨����
void CreateCycleListTail(LinkCycleList *&list, ElemType data[], int n)
{
	list = new LinkCycleList;
	list->data = -1;
	list->next = list; 
	LinkCycleList*r = list;
	for (int i = 0; i < n; i++)
	{
		LinkCycleList *node = new LinkCycleList;
		node->data = data[i];
		node->next = r->next;
		r->next = node;
		r = node;
	}
}


// ����ѭ���б�ĳ���
int ListLength(LinkCycleList *list)
{
	if (list == NULL)
		return 0;
	
	LinkCycleList* head = list;
	LinkCycleList* p = list->next;
	int i = 1;
	while (p->next != head)
	{
		p = p->next;
		i++;
	}

	return i;
}

// ��i��λ�ò���ڵ�data
Status InsertNodeCycleList(LinkCycleList *&list, int i, ElemType data)
{
	if (list == NULL)
		return OK;

	LinkCycleList* head = list;
	LinkCycleList *p = list;
	int j = 1;
	while (p->next != head && j < i)
	{

		p = p->next;
		j++;
	}

	if (p->next == head || j > i)
	{
		return ERROR;
	}
	
	LinkCycleList* node = (LinkCycleList*)malloc(sizeof(LinkCycleList));
	node->data = data;

	node->next = p->next;
	p->next = node;

	return OK;
}

// ɾ��iλ�õĽڵ�
Status DeleteNodeCycleList(LinkCycleList *&list, int i, ElemType *data)
{
	if (list == NULL)
		return ERROR;

	// q��Ҫɾ���Ľڵ㣬���ǵ��ҵ�������һ���ڵ����
	LinkCycleList* head = list;
	LinkCycleList* p = list;
	int j = 1;
	while (p->next != head && j < i)
	{
		p = p->next;
		j++;
	}

	if (p->next == head || j > i)
	{
		return ERROR;
	}

	LinkCycleList* q = p->next;
	*data = q->data;
	p->next = q->next;
	free(q);

	return OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//����ѭ���б�
	ElemType data[3] = {3,2,1};
	LinkCycleList *list = NULL;
	CreateCycleListTail(list, data, sizeof(data)/sizeof(int));

	LinkCycleList* head = list;
	LinkCycleList* tempNode = list;
	while (1)
	{
		printf("%d->", tempNode->data);
		if (tempNode->next == head)
			break;
		tempNode = tempNode->next;
	}
	printf("%d\n",head->data);

	// ɾ���ڵ�
	ElemType deleteData = 0;
	DeleteNodeCycleList(list, 2, &deleteData);

	head = list;
	tempNode = list;
	while (1)
	{
		printf("%d->", tempNode->data);
		if (tempNode->next == head)
			break;
		tempNode = tempNode->next;
	}
	printf("%d\n",head->data);
	printf("ɾ���Ľڵ�ֵ:%d\r\n", deleteData);

	//����ڵ�
	int insertData = 2;
	InsertNodeCycleList(list, 2, insertData);
	head = list;
	tempNode = list;
	while (1)
	{
		printf("%d->", tempNode->data);
		if (tempNode->next == head)
			break;
		tempNode = tempNode->next;
	}
	printf("%d\n",head->data);
	printf("����Ľڵ�ֵ:%d\n", insertData);

	int nLenth = ListLength(list);
	printf("ѭ���б���:%d\n",nLenth);
	return 0;
}

