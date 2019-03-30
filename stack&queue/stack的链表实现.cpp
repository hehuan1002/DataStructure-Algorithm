//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode,*pStackNode;


// ������ʵ��ջ��������ʵ��ջ��һЩ���ƣ�����һ�����Ǵ�С�������ƣ����������ơ�
// �������ڴ�ʹ���ϣ�����ջ��������һЩ(��1������)����Ϊÿ��Ԫ�ض���һ��ָ�롣

class CStackList
{
public:
	CStackList()
	{
		// ����Ҫһ���յ�top�ڵ㣬����ֱ�Ӱ�top��ʼ��ΪNULL [3/30/2019 hehuan] 
		/*top = (StackNode*)malloc(sizeof(StackNode));
		top->data = 0;
		top->next = NULL;*/
		int test = sizeof(StackNode);// test����8
		top = NULL;
		count = 0;
	}
	~CStackList()
	{
		// �ͷ�
		while (top)
		{
			StackNode* node = top->next;
			free(top);
			top = node;
		}
		count=0;
	}
public:

	// ���
	void visit(int c)
	{
		printf("%d ",c);
	}
	
	//ջ��С
	int size()
	{
		return count;
	}

	// �Ƿ�Ϊ��
	bool empty()
	{
		return (count==0)?true:false;
	}

	//ȡջ��Ԫ��
	int GetTop()
	{
		if (count == 0)
		{
			printf("��ջ��ȡ����ջ��Ԫ��!\n");
			return -1;
		}

		return top->data;
	}

	void Traverse()
	{
		printf("���ֵ: ");
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
			printf("��ջ!\n");
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
	// ���ݽṹ
	StackNode *top;
	int count;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CStackList stacklist;
	stacklist.push(1);
	stacklist.push(2);
	stacklist.push(3);

	// ���
	stacklist.Traverse();
	
	int result = stacklist.GetTop();
	printf("ջ��Ԫ�أ�%d", result);

	// ��ջ
	stacklist.pop();
	stacklist.pop();
	stacklist.pop();
	stacklist.pop();

	result = stacklist.GetTop();
	printf("ջ��Ԫ�أ�%d", result);

	return 0;
}