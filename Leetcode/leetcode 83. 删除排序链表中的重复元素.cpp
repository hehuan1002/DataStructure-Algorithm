// TestReverse.cpp : 定义控制台应用程序的入口点。
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

//指针引用
void CreateListHead(LinkList *&list, int data[], int n)
{
	list = new LinkList;
	list->next = NULL; //首先创建一个头节点，next赋值为NULL。
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