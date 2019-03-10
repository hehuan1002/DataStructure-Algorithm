// TestReverse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdlib.h"


#define CAPACITY 3

template<class T>
class Array
{
public:

	// ��ʼ��
	Array(int ncapacity = CAPACITY)
	{
		m_pdata = (T*)malloc(ncapacity *sizeof(T));
		m_ncapacity = ncapacity;
		m_nsize = 0;
	}

	~Array()
	{
		free(m_pdata);
		m_pdata = NULL;

		m_nsize = 0;
		m_ncapacity = 0;
	}

	// ����
	void resize(int ncapacity)
	{
		if (m_nsize > ncapacity)
		{
			return;
		}

		T* data = (T*)malloc(ncapacity *sizeof(T));
		memmove(data, m_pdata, m_nsize*sizeof(T));

		free(m_pdata);
		m_pdata = NULL;

		m_pdata = data;
		m_ncapacity = ncapacity;
	}

	int GetSize()
	{
		return m_nsize;
	}

	int GetCapacity()
	{
		return m_ncapacity;
	}

	bool IsEmpty()
	{
		return (m_nsize == 0)?true:false;
	}

	void addFirst(T data)
	{
		adddata(0, data);
	}

	void addLast(T data)
	{
		adddata(m_nsize, data);
	}


	void adddata(int nIndex, T data)
	{
		if (nIndex < 0 || nIndex > m_nsize)
		{
			return;
		}

		// 2������
		if (m_nsize >= m_ncapacity)
		{
			visit();
			resize(2*CAPACITY);
			visit();
		}


		// �������
		for (int i = m_nsize; i > nIndex; i--)
		{
			m_pdata[i] = m_pdata[i-1];
		}

		m_pdata[nIndex] = data;
		m_nsize++;

		printf("Index:%d, nSize:%d\n", nIndex, m_nsize);
	}

	void visit()
	{
		if (m_nsize <= 0)
		{
			printf("null");
			return;
		}

		for (int i = 0; i < m_nsize-1; i++)
		{
			printf("%d,", m_pdata[i]);
		}
		for (int i = m_nsize - 1; i < m_nsize; i++)
		{
			printf("%d", m_pdata[i]);
		}
		printf("\n");
	}

	T removefirst()
	{
		if (m_nsize <= 0)
		{
			return NULL;
		}

		T result = m_pdata[0];
		remove(0);

		return result;
	}

	T removelast()
	{
		T result = m_pdata[m_nsize];
		m_nsize--;

		return result;
	}
	T remove(int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nsize)
		{
			return NULL;
		}

		T result = m_pdata[nIndex];
		m_nsize--;

		for (int i = nIndex; i < m_nsize; i++)
		{
			m_pdata[i] = m_pdata[i+1];
		}

		// ����
		/*if (m_nsize < m_ncapacity/2)
		{
			resize(m_ncapacity/2);
		}*/

		return result;
	}

	void set(int nIndex ,T data)
	{
		if (nIndex < 0 || nIndex >= m_nsize)
		{
			return;
		}

		m_pdata[nIndex] = data;
	}

	bool contains(T num)
	{
		for (int i = 0; i < m_nsize; i++)
		{
			if (m_pdata[i] == num)
			{
				return true;
			}
		}

		return false;
	}

   // ����������ȡֵ
	T Get(int nIndex)
	{
		// nIndex>m_nsize�����������
		if (nIndex < 0 || nIndex >= m_nsize)
		{
			return -1;
		}

		return m_pdata[nIndex];
	}

	// ����ֵ������
	int find(T num)
	{
		for (int i = 0; i < m_nsize; i++)
		{
			if (m_pdata[i] == num)
			{
				return i;
			}
		}

		return -1;
	}
private:
	T* m_pdata;// �����׵�ַ
	int m_nsize; //�����С
	int m_ncapacity; // ��������
};

int _tmain(int argc, _TCHAR* argv[])
{	
	
	Array<int> dd;
	for (int i = 0; i < 3; i++)
	{
		dd.adddata(i,i);
	}

	/*dd.addFirst(45);
	dd.visit();

	dd.remove(3);
	dd.visit();

	dd.remove(2);
	dd.visit();

	dd.remove(1);
	dd.visit();*/

	// ����removeFirst
	dd.removefirst();
	dd.visit();

	dd.removefirst();
	dd.visit();

	dd.removefirst();
	dd.visit();

	dd.removefirst();
	dd.visit();

	return 0;
}


//https://blog.csdn.net/qq_35481167/article/details/83860020