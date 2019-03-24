//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#define MAXSIZE 4


// 循环队列的实现，在push的时候是需要对MAXSIZE取模的。
template<class T>
class CQueue
{
public:
	CQueue()
	{
		m_pdata = (T*)malloc(sizeof(T)*MAXSIZE);
		m_nrear = 0;
		m_nfront = 0;
	}
	~CQueue()
	{
		free(m_pdata);
		m_nrear = 0;
		m_nfront = 0;
	}
public:

	void visit(T data)
	{
		printf("%d ", data);
	}


	void clearqueue()
	{
		m_nfront=m_nrear=0;
	}

	bool empty()
	{
		return (m_nfront==m_nrear)?true:false;
	}

	T gettop()
	{
		if (empty())
		{
			return -1;
		}

		return m_pdata[m_nfront];
	}

	// 从队头到队尾依次输出
	void QueueTraverse()
	{ 
		int i = m_nfront;
		while ((i%MAXSIZE) == m_nrear)
		{
			visit(m_pdata[]);
			i = (i+1)%MAXSIZE;
		}
	}

	int size()
	{
		return (m_nrear - m_nfront+ MAXSIZE)%MAXSIZE;
	}

	void push(T data)
	{
		// 问题处？ 队满的判断，如果是这样判断，说明少存了一个，比较奇怪？
		if ((m_nrear+1) %MAXSIZE == m_nfront)
		{
			printf("队列已满\n");
			return;
		}

		printf("%d ", data);
		m_pdata[m_nrear] = data;
		m_nrear = (m_nrear+1)%MAXSIZE;// 当存满4个元素的时候，结果rear=0了？？？？

	}

	T pop()
	{
		if (m_nfront == m_nrear)
		{
			printf("队列已空\n");
            return -1;
		}

		T ret = m_pdata[m_nfront];
		m_nfront = (m_nfront+1)%MAXSIZE;
		return ret;
	}
private:
	T *m_pdata; // 数据，类型为T
	int m_nfront; // 头
	int m_nrear; // 尾

};

int _tmain(int argc, _TCHAR* argv[])
{
	//
	CQueue<int> queue;

	// 
	printf("入队\n");
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	return 0;
}