//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "memory.h"
#include <stack>

#define MAXSIZE 10
template<class T>
class CStack
{
public:
	CStack()
	{
		m_data = new T[MAXSIZE];
		memset(m_data, 0, MAXSIZE*sizeof(T));
		m_nTop = -1;// �����Ǵ�0��ʼ�ģ���ʼ��Ϊ-1�ȽϺ���
	}
	~CStack()
	{
		delete [] m_data;
		m_data = NULL;
		m_nTop = -1;
	}

	void ClearStack()
	{
		m_nTop = -1; // ֻ��Ҫ��top�ĳ�-1���ɣ�������Ҫ���ڴ��ͷ�
	}


	// ���
	void visit(T c)
	{
		printf("%d ",c);
	}

	// ȡջ��Ԫ��
	T GetTop()
	{
		if (m_nTop == -1){
			return -1;
		}

		return m_data[m_nTop];
	}

	// �Ƿ�Ϊ��
	bool empty()
	{
		return (m_nTop == -1) ? true: false;
	}

	// ջ�ĳ���
	int size()
	{
		return m_nTop+1;
	}

	void Traverse_2()
	{
		while (m_nTop >= 0){
			visit(m_data[m_nTop--]);
		}
		printf("\n");
	}

	void Traverse()
	{
		int i = 0;
		while (i <= m_nTop){
			visit(m_data[i++]);
		}
		printf("\n");
	}

	// ��ջ
	void push(T data)
	{
		if (m_nTop == MAXSIZE-1){
			return;
		}

		m_nTop++;
		m_data[m_nTop] = data;
	}

	// ��ջ
	T pop()
	{
		if (m_nTop == -1){
			return -1;
		}

		T ret = m_data[m_nTop];
		m_nTop--;
		return ret;
	}


private:
	T *m_data;
	int m_nTop; // ����ջ��λ�õı���
};


int _tmain(int argc, _TCHAR* argv[])
{
	CStack<int> stack;

	// 3��Ԫ�ؽ�ջ
	stack.push(1);
	stack.push(2);
	stack.push(3);

	int nLength = stack.size();
	printf("ջ�Ĵ�С��%d\n", nLength);

	bool result = stack.empty();
	printf("ջ�Ƿ�Ϊ�գ�%d\n", result);

	int topResult = stack.GetTop();
	printf("ջ��Ԫ�أ�%d\n", topResult);

	// ��ջ����ջ����ӡ
	stack.Traverse();

	// ��ջ����ջ�״�ӡ
	stack.Traverse_2();

	// ���ջ,������ջ֮����pop��Ȼʧ�ܣ��мǡ�
	//stack.ClearStack();

	// 3��Ԫ�س�ջ
	int n1 = stack.pop();
	int n2 = stack.pop();
	int n3 = stack.pop();
	return 0;
}