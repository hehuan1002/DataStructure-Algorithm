//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

typedef struct QueueNode
{
	int data;
	struct QueueNode* next;

}QueueNode,*pQeueNode;

class CQueueList
{
public:
	CQueueList()
	{
		//��ʼ��ͷ��㣬���Ǳ���Ҫ��
		QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));
		head->data = 0;
		front=rear=head;
	}

	~CQueueList()
	{
		// ����ͷ�ڵ�
		QueueNode* head = front->next;
		while (head)
		{
			QueueNode* node = head->next;
			free(head);
			head=node;
		}
	}


public:
	void visit(int data)
	{
		printf("%d ", data);
	}

	int gettop()
	{
		if (rear == front)
		{
			return -1;
		}
		
		return front->next->data;
	}

	// �Ӷ�ͷ����β�������
	void QueueTraverse()
	{ 
		QueueNode* head = front->next;
		while (head)
		{
			visit(head->data);
			head=head->next;
		}
		printf("\n");
	}

	void push(int data)
	{
		printf("%d ", data);
		QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
		node->data = data;
		node->next = NULL;

		rear->next = node; //���½ڵ㸳ֵ��rear�ĺ��
		rear = node; // rear�ڵ�ָ���µĽڵ�
	}

	int pop()
	{
		// �ն��е��ж�
		if (rear == front)
		{
			return -1;
		}

		QueueNode *node = front->next;
		int ret = node->data;
		printf("%d ", ret);
		front->next = node->next;

		// ��ֻʣ��һ���ڵ�ʱ
		if (rear == node)
		{
			rear = front;
		}

		free(node);
		return ret;
	}
private:
	// ���ݽṹ
	QueueNode* front;
	QueueNode* rear;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CQueueList queue;
	printf("���: ");
	queue.push(1);
	queue.push(2);
	printf("\n");

	queue.QueueTraverse();

	printf("���ӣ�");
	queue.pop();
	queue.pop();
	printf("\n");

	return 0;
}