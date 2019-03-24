//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#define MAXSIZE 4


// ѭ�����е�ʵ�֣���push��ʱ������Ҫ��MAXSIZEȡģ�ġ�
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

	// �Ӷ�ͷ����β�������
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
		// ���⴦�� �������жϣ�����������жϣ�˵���ٴ���һ�����Ƚ���֣�
		if ((m_nrear+1) %MAXSIZE == m_nfront)
		{
			printf("��������\n");
			return;
		}

		printf("%d ", data);
		m_pdata[m_nrear] = data;
		m_nrear = (m_nrear+1)%MAXSIZE;// ������4��Ԫ�ص�ʱ�򣬽��rear=0�ˣ�������

	}

	T pop()
	{
		if (m_nfront == m_nrear)
		{
			printf("�����ѿ�\n");
            return -1;
		}

		T ret = m_pdata[m_nfront];
		m_nfront = (m_nfront+1)%MAXSIZE;
		return ret;
	}
private:
	T *m_pdata; // ���ݣ�����ΪT
	int m_nfront; // ͷ
	int m_nrear; // β

};

int _tmain(int argc, _TCHAR* argv[])
{
	//
	CQueue<int> queue;

	// 
	printf("���\n");
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	return 0;
}