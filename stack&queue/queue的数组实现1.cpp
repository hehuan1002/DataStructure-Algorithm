//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define MAXSIZE 10


template<class T>
class CQueue
{
public:
	CQueue()
	{
		m_pData = new int[sizeof(int)*MAXSIZE];
		m_nfront = 0; // 由-1改为0是有原因的。
		m_nrear = 0;
	}
	~CQueue()
	{
		delete []m_pData;
		m_pData = NULL;
		m_nfront = 0;
		m_nrear = 0;
	}
public:

	void visit(int data)
	{
		printf("%d ", data);
	}


	void clearqueue()
	{
		m_nfront = 0;
		m_nrear = 0;
	}

	bool empty()
	{
		return (m_nfront==m_nrear) ? true:false;
	}

	int gettop()
	{
		if (empty())
		{
			return -1;
		}

		//m_nfront++; // m_nfront默认为-1时，取值是有问题的。只是取值不会把值pop掉
		return m_pData[m_nfront];
	}

	// 从队头到队尾依次输出
	void QueueTraverse()
	{ 
		int i = m_nfront;
		while (i != m_nrear)
		{
			visit(m_pData[i]);
			i++;
		}
		printf("\n");
	}

	int size()
	{
		return m_nrear - m_nfront;
	}

	void push(int data)
	{
		if (m_nrear == MAXSIZE)
		{
			printf("\n队列已满，长度:%d\n", size());
			return;
		}

		m_pData[m_nrear] = data;
		m_nrear++;
		printf("%d ", data);
	}

	int pop()
	{
		if (m_nfront >= m_nrear)
		{
			printf("\n队列已空，长度:%d\n", size());
			return -1;
		}

		int ret = m_pData[m_nfront];
		m_nfront++;
		printf("%d ", ret);
		return ret;
	}
private:
	int *m_pData; //数据地址
	int m_nfront; // 队列头，初始化为0位置
	int m_nrear; // 指向队尾元素的下一个位置，初始化为0位置
};

int _tmain(int argc, _TCHAR* argv[])
{
	CQueue<int> queue;

	// 入队
	printf("入队: ");
	queue.push(0);
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	queue.push(6);
	queue.push(7);
	queue.push(8);
	queue.push(9);
	queue.push(10);

	// 输出其值
	queue.QueueTraverse();

	// 取队头元素的值
	int nfront = queue.gettop();
	printf("队列头元素:%d\n", nfront);

	// 出队
	printf("出队：");
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();

	// 是否为空
	bool result = queue.empty();
	printf("队列是否为空:%d\n", result);

	//
	return 0;
}