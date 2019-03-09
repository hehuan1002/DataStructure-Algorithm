// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

//������ڵ�
typedef struct Node
{
	int nData;
	struct Node *next;
}LinkList;


//ָ������
void CreateListHead(LinkList *&list, int data[], int n)
{
	list = new LinkList;
	list->next = NULL; //���ȴ���һ��ͷ�ڵ㣬next��ֵΪNULL��
	for (int i = 0; i < n; i++)
	{
		LinkList *node = new LinkList;
		node->nData = data[i];

		node->next = list->next;
		list->next = node;
	}
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    LinkList* removeNthFromEnd(LinkList* head, int n) {
        if (head == NULL)
			return NULL;
		
		int length = 0;
		LinkList* p = head->next;
		while (p)
		{
			p = p->next;
			length++;
		}

		int pos = length - n; //ע�⼼�ɣ��ҵ�length - n +1��ǰһ���ڵ�length - n;
		LinkList* q = head;
		while (pos-- > 0)
		{
			q = q->next;
		}

		q->next = q->next->next;
		return head;
    }

	LinkList* removeNthFromEnd2(LinkList* head, int n) {
		if (head == NULL)
			return NULL;

		// firstָ����ǰ��n+1��
		LinkList* first = head->next;
		LinkList* second = head->next;
		
		for (int i = 1; i <=n+1; i++)
		{
			first = first->next;
		}

		while (first != NULL)
		{
			first = first->next;
			second = second->next;
		}

		second->next = second->next->next;
		return head;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	int data[5] = {1,2,3,4,5};
	LinkList *list = NULL;
	CreateListHead(list, data, sizeof(data)/sizeof(int));

	Solution sln;
	//sln.removeNthFromEnd(list,2);

	sln.removeNthFromEnd2(list, 2);
	return 0;
}