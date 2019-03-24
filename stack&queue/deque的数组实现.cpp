//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
// hehuan

#include "stdafx.h"
#define MAXSIZE 10


template<class T>
class CQueue
{
public:
	CQueue()
	{
		m_pData = new int[sizeof(int)*MAXSIZE];
		m_nfront = -1;
		m_nrear = -1;
	}
	~CQueue()
	{
		delete []m_pData;
		m_pData = NULL;
		m_nfront = -1;
		m_nrear = -1;
	}
public:

	void clearqueue()
	{
		m_nfront = -1;
		m_nrear = -1;
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

		m_nfront++;
		return m_pData[m_nfront];
	}

	int size()
	{
		return m_nrear - m_nfront;
	}

	void push(int data)
	{
		if (m_nrear == MAXSIZE-1)
		{
			printf("��������������:%d\n", size());
			return;
		}

		m_nrear++;
		m_pData[m_nrear] = data;
		printf("%d ", data);
	}

	int pop()
	{
		if (m_nfront >= m_nrear)
		{
			printf("�����ѿգ�����:%d\n", size());
			return -1;
		}

		m_nfront++;
		int ret = m_pData[m_nfront];
		printf("%d ", ret);
		return ret;
	}
private:
	int *m_pData; //���ݵ�ַ
	int m_nfront; // ����ͷ
	int m_nrear; // ����β
};

int _tmain(int argc, _TCHAR* argv[])
{
	CQueue<int> queue;

	// ���
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

	// 
	int nfront = queue.gettop();
	printf("����ͷ:%d", nfront);

	// ����
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
	queue.pop();

	// �Ƿ�Ϊ��
	bool result = queue.empty();
	printf("�����Ƿ�Ϊ��:%d\n", result);

	//
	return 0;
}