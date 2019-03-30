//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#define MAXSIZE 10


template<class T>
class CQueue
{
public:
	CQueue()
	{
		m_pData = new int[sizeof(int)*MAXSIZE];
		memset(m_pData, 0, sizeof(int)*MAXSIZE);
		m_nrear = 0;
	}
	~CQueue()
	{
		delete []m_pData;
		m_pData = NULL;
		m_nrear = 0;
	}
public:

	void visit(int data)
	{
		printf("%d ", data);
	}


	void clearqueue()
	{
		m_nrear = 0;
	}

	bool empty()
	{
		return (0==m_nrear) ? true:false;
	}

	int gettop()
	{
		if (empty())
		{
			return -1;
		}

		return m_pData[0];
	}

	// 从队头到队尾依次输出
	void QueueTraverse()
	{ 
		int i = 0;
		while (i != m_nrear)
		{
			visit(m_pData[i]);
			i++;
		}
		printf("\n");
	}

	int size()
	{
		return m_nrear;
	}

	void push(int data)
	{
		if (m_nrear == MAXSIZE)
		{
			printf("队列已满，长度:%d\n", size());
			return;
		}

		m_pData[m_nrear] = data;
		m_nrear++;
		printf("%d ", data);
	}

	int pop()
	{
		if (m_nrear == 0)
		{
			printf("\n队列已空，长度:%d\n", size());
			return -1;
		}

		// 始终取下标为0的数据，并把1--m_nrear的数据前移一位。
		int ret = m_pData[0];
		for(int i = 0; i < m_nrear; i++)
		{
			m_pData[i] = m_pData[i+1];
		}
		m_nrear--;

		printf("%d ", ret);
		return ret;
	}
private:
	int *m_pData; //数据地址
	int m_nrear; // 队列尾，队列头永远是0
};

int _tmain(int argc, _TCHAR* argv[])
{
	CQueue<int> queue;

	// 入队
	printf("入队: ");
	queue.push(1);
	queue.push(2);
	queue.push(3);
	printf("\n");

	// 输出其值
	queue.QueueTraverse();

	// 取队头元素的值
	int nfront = queue.gettop();
	printf("队列头元素:%d\n", nfront);

	// 出队
	printf("出队: ");
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();

	// 输出其值
	queue.QueueTraverse();

	// 是否为空
	bool result = queue.empty();
	printf("队列是否为空:%d\n", result);

	//
	return 0;
}