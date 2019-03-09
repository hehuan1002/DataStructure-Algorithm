// TestReverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkCycleList;



//创建循环列表, 尾插法创建
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


// 返回循环列表的长度
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

// 在i个位置插入节点data
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

// 删除i位置的节点
Status DeleteNodeCycleList(LinkCycleList *&list, int i, ElemType *data)
{
	if (list == NULL)
		return ERROR;

	// q是要删除的节点，但是得找到它的上一个节点才行
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
	//创建循环列表
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

	// 删除节点
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
	printf("删除的节点值:%d\r\n", deleteData);

	//插入节点
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
	printf("插入的节点值:%d\n", insertData);

	int nLenth = ListLength(list);
	printf("循环列表长度:%d\n",nLenth);
	return 0;
}

