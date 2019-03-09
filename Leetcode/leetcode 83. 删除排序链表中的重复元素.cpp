// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node
{
	int Data;
	struct Node *next;
}LinkList;

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
    LinkList* deleteDuplicates(LinkList* head) {
        LinkList* p = head;
		while (p != NULL && p->next != NULL)
		{
			if (p->Data == p->next->Data)
				p->next = p->next->next;
			else
				p = p->next;
		}

		return head;
    }
};

//ָ������
void CreateListHead(LinkList *&list, int data[], int n)
{
	list = new LinkList;
	list->next = NULL; //���ȴ���һ��ͷ�ڵ㣬next��ֵΪNULL��
	for (int i = 0; i < n; i++)
	{
		LinkList *node = new LinkList;
		node->Data = data[i];

		node->next = list->next;
		list->next = node;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{	
	int data[4] = {3,2,2,1};
	LinkList *list = NULL;
	CreateListHead(list, data, sizeof(data)/sizeof(int));

	Solution sln;
	LinkList* result = sln.deleteDuplicates(list);
	return 0;
}