//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode,*pStackNode;


// 用链表实现栈比用数组实现栈有一些优势，其中一条就是大小不受限制，可以无限制。
// 但是在内存使用上，链表栈开销更高一些(多1倍开销)，因为每个元素多了一个指针。

class CStackList
{
public:
	CStackList()
	{
		// 不需要一个空的top节点，而是直接把top初始化为NULL [3/30/2019 hehuan] 
		/*top = (StackNode*)malloc(sizeof(StackNode));
		top->data = 0;
		top->next = NULL;*/
		int test = sizeof(StackNode);// test等于8
		top = NULL;
		count = 0;
	}
	~CStackList()
	{
		// 释放
		while (top)
		{
			StackNode* node = top->next;
			free(top);
			top = node;
		}
		count=0;
	}
public:

	// 输出
	void visit(int c)
	{
		printf("%d ",c);
	}
	
	//栈大小
	int size()
	{
		return count;
	}

	// 是否为空
	bool empty()
	{
		return (count==0)?true:false;
	}

	//取栈顶元素
	int GetTop()
	{
		if (count == 0)
		{
			printf("空栈，取不到栈顶元素!\n");
			return -1;
		}

		return top->data;
	}

	void Traverse()
	{
		printf("输出值: ");
		StackNode* node = top;
		while (node)
		{
			visit(node->data);
			node = node->next;
		}
		printf("\n");
	}
	void push(int data)
	{
		StackNode *node = (StackNode*)malloc(sizeof(StackNode));
		node->data = data;
		node->next = top;

		top = node;
		count++;
	}

	int pop()
	{
		if (count == 0)
		{
			printf("空栈!\n");
			return -1;
		}

		int ret = top->data;
		StackNode* node = top->next;
		free(top);
		top = node;
		count--;

		return ret;
	}


private:
	// 数据结构
	StackNode *top;
	int count;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CStackList stacklist;
	stacklist.push(1);
	stacklist.push(2);
	stacklist.push(3);

	// 输出
	stacklist.Traverse();
	
	int result = stacklist.GetTop();
	printf("栈顶元素：%d", result);

	// 出栈
	stacklist.pop();
	stacklist.pop();
	stacklist.pop();
	stacklist.pop();

	result = stacklist.GetTop();
	printf("栈顶元素：%d", result);

	return 0;
}