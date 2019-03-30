//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
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
		m_nfront = 0; // ��-1��Ϊ0����ԭ��ġ�
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

		//m_nfront++; // m_nfrontĬ��Ϊ-1ʱ��ȡֵ��������ġ�ֻ��ȡֵ�����ֵpop��
		return m_pData[m_nfront];
	}

	// �Ӷ�ͷ����β�������
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
			printf("\n��������������:%d\n", size());
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
			printf("\n�����ѿգ�����:%d\n", size());
			return -1;
		}

		int ret = m_pData[m_nfront];
		m_nfront++;
		printf("%d ", ret);
		return ret;
	}
private:
	int *m_pData; //���ݵ�ַ
	int m_nfront; // ����ͷ����ʼ��Ϊ0λ��
	int m_nrear; // ָ���βԪ�ص���һ��λ�ã���ʼ��Ϊ0λ��
};

int _tmain(int argc, _TCHAR* argv[])
{
	CQueue<int> queue;

	// ���
	printf("���: ");
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

	// �����ֵ
	queue.QueueTraverse();

	// ȡ��ͷԪ�ص�ֵ
	int nfront = queue.gettop();
	printf("����ͷԪ��:%d\n", nfront);

	// ����
	printf("���ӣ�");
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