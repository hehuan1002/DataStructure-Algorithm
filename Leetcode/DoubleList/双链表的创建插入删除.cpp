// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdlib.h"


typedef struct Node
{
	int data;
    struct Node* next;
	struct Node* pre;

}DoubleLinklist;

void CreateDoubleLinklistByTail(DoubleLinklist*& list, int data[], int n)
{
	list = (DoubleLinklist*)malloc(sizeof(DoubleLinklist));
	list->next = NULL;
	list->pre = NULL;
	DoubleLinklist* r = list;
	for (int i = 0; i < n; i++)
	{
		DoubleLinklist* node = (DoubleLinklist*)malloc(sizeof(DoubleLinklist));
		node->data = data[i];

		r->next = node;
		node->pre = r;

		r = node;
	}

	r->next = NULL;
}

DoubleLinklist* GetElemP_DuL(DoubleLinklist* va, int i)
{  
  // LΪ��ͷ���ĵ������ͷָ�롣
  // ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
  DoubleLinklist* p;
  p = va->next;   
  int j = 1;  // ��ʼ����pָ���һ����㣬jΪ������
  while (p!=va && j<i) { //˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
    p = p->next;
    ++j;
  }
  if (p==va && j<i) return NULL;  // ��i��Ԫ�ز�����
  else return p;
} // GetElem_L


int ListInsert_DuL(DoubleLinklist *&L, int i, int e) { //�㷨2.18
  // �ڴ�ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e��
  // i�ĺϷ�ֵΪ1��i�ܱ�+1��
  DoubleLinklist *p,*s;
  if (!(p = GetElemP_DuL(L, i)))  // ��L��ȷ����i��Ԫ�ص�λ��ָ��p
    return -1;                 // p=NULL, ����i��Ԫ�ز�����
  if (!(s = (DoubleLinklist*)malloc(sizeof(DoubleLinklist))))
    return -1;
  s->data = e;
  s->pre = p->pre;
  p->pre->next = s;
  s->next = p;
  p->pre = s;
  return 1;
} // ListInsert_DuL



void ListInsert(DoubleLinklist *list, int i, int data)
{
	if (NULL == list){
		return;
	}

	DoubleLinklist* p = list->next;
	int j = 1;
	while(NULL != p && j < i)
	{
		p = p->next;
		j++;
	}
	
	if (NULL == p || j > i)
		return;

	DoubleLinklist* node = (DoubleLinklist*)malloc(sizeof(DoubleLinklist));
	node->data = data;

	// ��i��Ԫ��֮�����Ԫ��data
	node->next = p->next;
	node->pre = p;
	p->next->pre = node;  // �����⣬���p->nextΪ�յĻ��� ��ôp->next->pre�ͻᱨ��
	p->next = node;
}


void ListInsert2(DoubleLinklist *list, int i, int data)
{
	if (NULL == list){
		return;
	}

	DoubleLinklist* p = list->next;
	int j = 1;
	while(NULL != p && j < i)
	{
		p = p->next;
		j++;
	}
	
	if (NULL == p || j > i)
		return;

	DoubleLinklist* node = (DoubleLinklist*)malloc(sizeof(DoubleLinklist));
	node->data = data;

	// ��i��Ԫ��֮ǰ����Ԫ��data�������Ͳ���������
	node->pre = p->pre;
	p->pre->next = node;
	node->next = p;
	p->pre = node;
}


void ListDelete(DoubleLinklist *list, int i, int data)
{
	if (NULL == list){
		return;
	}

	// ����ֱ���ҵ���i���ڵ㣬ɾ�����ɣ�����������������
	// ��Ϊ˫�������ҵ�����pre��next�ڵ㡣
	DoubleLinklist* p = list->next;
	int j = 1;
	while(NULL != p->next && j < i)
	{
		p = p->next;
		j++;
	}
	
	if (NULL == p->next || j > i)
		return;

	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
	p = NULL;
}



int _tmain(int argc, _TCHAR* argv[])
{	
	// ����һ���б�
	int data[4] = {1, 2, 3, 4};
	DoubleLinklist* list = NULL;
	CreateDoubleLinklistByTail(list, data, sizeof(data)/sizeof(int));

	struct Node *tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->data);
		tempNode = tempNode->next;
	}

	printf("NULL\n");

	// ���뵽���ĸ�λ��
	ListInsert2(list, 4, 5);
	tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->data);
		tempNode = tempNode->next;
	}

	printf("NULL\n");

	//ɾ�����ĸ��ڵ�
	ListDelete(list,4,5);
	tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->data);
		tempNode = tempNode->next;
	}

	printf("NULL\n");
	return 0;
}