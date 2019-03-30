//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
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

	// �Ӷ�ͷ����β�������
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
			printf("��������������:%d\n", size());
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
			printf("\n�����ѿգ�����:%d\n", size());
			return -1;
		}

		// ʼ��ȡ�±�Ϊ0�����ݣ�����1--m_nrear������ǰ��һλ��
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
	int *m_pData; //���ݵ�ַ
	int m_nrear; // ����β������ͷ��Զ��0
};

int _tmain(int argc, _TCHAR* argv[])
{
	CQueue<int> queue;

	// ���
	printf("���: ");
	queue.push(1);
	queue.push(2);
	queue.push(3);
	printf("\n");

	// �����ֵ
	queue.QueueTraverse();

	// ȡ��ͷԪ�ص�ֵ
	int nfront = queue.gettop();
	printf("����ͷԪ��:%d\n", nfront);

	// ����
	printf("����: ");
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();

	// �����ֵ
	queue.QueueTraverse();

	// �Ƿ�Ϊ��
	bool result = queue.empty();
	printf("�����Ƿ�Ϊ��:%d\n", result);

	//
	return 0;
}