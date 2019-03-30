//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4


// ѭ�����е�ʵ�֣���push��ʱ������Ҫ��MAXSIZEȡģ�ġ�

/***********�ж϶�����*********/
// �����п�ʱ��m_nrear==m_nfront����������ʱ��Ҳ��m_nrear==m_nfront����ô����ж϶����ǿջ�������
// CQueue���õĶ�����ʱ�������л���һ�����е�Ԫ��
// ���ù�ʽ"��m_nrear+1��% MAXSIZE == m_nfront"���ж϶�������ȡģ��Ŀ����Ϊ������m_nrear��m_nfrontΪһȦ���⡣

/**********�����б���***********/
// ��m_nrear����m_nfrontʱ���б���Ϊm_nrear-m_nfront����m_rearС��m_nfrontʱ,�����μ��㣬һ����MAXSIZE-m_nfront��һ����0+m_nrear��
// ���ù�ʽ"(m_nrear-m_nfont+MAXSIZE)%MAXSIZE"��������г���
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

	// �Ӷ�ͷ����β�������
	void QueueTraverse()
	{ 
		// TODO: ������������ģ���֪����ν�������� [3/30/2019 hehuan]
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
			printf("\n��������\n");
			return;
		}

		printf("%d ", data);
		m_pdata[m_nrear] = data;
		m_nrear = (m_nrear+1)%MAXSIZE;// ȡģ��Ϊ�˽��һȦ������
	}

	T pop()
	{
		if (m_nfront == m_nrear)
		{
			printf("�����ѿ�\n");
			return -1;
		}

		T ret = m_pdata[m_nfront];
		m_nfront = (m_nfront+1)%MAXSIZE; // ȡģ��Ϊ�˽��һȦ������
		return ret;
	}
private:
	T *m_pdata; // ���ݣ�����ΪT
	int m_nfront; // ͷָ�룬��ʼ��Ϊ0λ��
	int m_nrear; // βָ�룬ָ���βԪ�ص���һ��λ�ã���ʼ��Ϊ0λ�ã���m_nrear==3ʱ�����о����ˡ�

};

int _tmain(int argc, _TCHAR* argv[])
{
	//
	CQueue<int> queue;

	// 
	printf("��ӣ�");
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);

	queue.QueueTraverse();
	printf("���г��ȣ�%d\n", queue.size());

	queue.pop();
	queue.pop();
	queue.QueueTraverse();
	printf("���г��ȣ�%d\n", queue.size());

	return 0;
}