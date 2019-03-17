// TestReverse.cpp : 定义控制台应用程序的入口点。
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
  // L为带头结点的单链表的头指针。
  // 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
  DoubleLinklist* p;
  p = va->next;   
  int j = 1;  // 初始化，p指向第一个结点，j为计数器
  while (p!=va && j<i) { //顺指针向后查找，直到p指向第i个元素或p为空
    p = p->next;
    ++j;
  }
  if (p==va && j<i) return NULL;  // 第i个元素不存在
  else return p;
} // GetElem_L


int ListInsert_DuL(DoubleLinklist *&L, int i, int e) { //算法2.18
  // 在带头结点的双链循环线性表L的第i个元素之前插入元素e，
  // i的合法值为1≤i≤表长+1。
  DoubleLinklist *p,*s;
  if (!(p = GetElemP_DuL(L, i)))  // 在L中确定第i个元素的位置指针p
    return -1;                 // p=NULL, 即第i个元素不存在
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

	// 在i个元素之后插入元素data
	node->next = p->next;
	node->pre = p;
	p->next->pre = node;  // 有问题，如果p->next为空的话， 那么p->next->pre就会报错。
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

	// 在i个元素之前插入元素data，这样就不存在问题
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

	// 这里直接找到第i个节点，删除即可，跟单链表有所区别。
	// 因为双链表能找到它的pre和next节点。
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
	// 创建一个列表
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

	// 插入到第四个位置
	ListInsert2(list, 4, 5);
	tempNode = list->next;
	while (tempNode)
	{
		printf("%d->", tempNode->data);
		tempNode = tempNode->next;
	}

	printf("NULL\n");

	//删除第四个节点
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