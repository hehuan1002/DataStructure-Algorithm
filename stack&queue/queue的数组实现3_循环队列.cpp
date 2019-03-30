//// TestMemset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4


// 循环队列的实现，在push的时候是需要对MAXSIZE取模的。

/***********判断队列满*********/
// 当队列空时，m_nrear==m_nfront；当队列满时，也是m_nrear==m_nfront，那么如何判断队列是空还是满？
// CQueue采用的队列满时，数组中还有一个空闲单元。
// 采用公式"（m_nrear+1）% MAXSIZE == m_nfront"来判断队列满，取模的目的是为了整合m_nrear和m_nfront为一圈问题。

/**********计算列表长度***********/
// 当m_nrear大于m_nfront时，列表长度为m_nrear-m_nfront，当m_rear小于m_nfront时,分两段计算，一段是MAXSIZE-m_nfront，一段是0+m_nrear。
// 采用公式"(m_nrear-m_nfont+MAXSIZE)%MAXSIZE"来计算队列长度
template<class T>
class CQueue
{
public:
	CQueue()
	{
		m_pdata = (T*)malloc(sizeof(T)*MAXSIZE);
		memset(m_pdata, 0, sizeof(T)*MAXSIZE);
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
		// TODO: 这里是有问题的，不知道如何解决？？？ [3/30/2019 hehuan]
		int i = m_nfront;
		while ((i+m_nfront) != m_nrear)
		{
			visit(m_pdata[i]);
			i = (i+1)%MAXSIZE;
		}
	}

	int size()
	{
		return (m_nrear-m_nfront+MAXSIZE)%MAXSIZE;
	}

	void push(T data)
	{
		if ((m_nrear+1) %MAXSIZE == m_nfront)
		{
			printf("\n队列已满\n");
			return;
		}

		printf("%d ", data);
		m_pdata[m_nrear] = data;
		m_nrear = (m_nrear+1)%MAXSIZE;// 取模是为了解决一圈的问题
	}

	T pop()
	{
		if (m_nfront == m_nrear)
		{
			printf("队列已空\n");
			return -1;
		}

		T ret = m_pdata[m_nfront];
		m_nfront = (m_nfront+1)%MAXSIZE; // 取模是为了解决一圈的问题
		return ret;
	}
private:
	T *m_pdata; // 数据，类型为T
	int m_nfront; // 头指针，初始化为0位置
	int m_nrear; // 尾指针，指向队尾元素的下一个位置，初始化为0位置，当m_nrear==3时，队列就满了。

};

int _tmain(int argc, _TCHAR* argv[])
{
	//
	CQueue<int> queue;

	// 
	printf("入队：");
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);

	queue.QueueTraverse();
	printf("队列长度：%d\n", queue.size());

	queue.pop();
	queue.pop();
	queue.QueueTraverse();
	printf("队列长度：%d\n", queue.size());

	return 0;
}