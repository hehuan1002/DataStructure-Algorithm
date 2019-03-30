//// TestMemset.cpp : 定义控制台应用程序的入口点。
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
		//初始化头结点，这是必须要的
		QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));
		head->data = 0;
		front=rear=head;
	}

	~CQueueList()
	{
		// 保留头节点
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

	// 从队头到队尾依次输出
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

		rear->next = node; //把新节点赋值给rear的后继
		rear = node; // rear节点指向新的节点
	}

	int pop()
	{
		// 空队列的判断
		if (rear == front)
		{
			return -1;
		}

		QueueNode *node = front->next;
		int ret = node->data;
		printf("%d ", ret);
		front->next = node->next;

		// 当只剩下一个节点时
		if (rear == node)
		{
			rear = front;
		}

		free(node);
		return ret;
	}
private:
	// 数据结构
	QueueNode* front;
	QueueNode* rear;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CQueueList queue;
	printf("入队: ");
	queue.push(1);
	queue.push(2);
	printf("\n");

	queue.QueueTraverse();

	printf("出队：");
	queue.pop();
	queue.pop();
	printf("\n");

	return 0;
}