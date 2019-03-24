//// TestMemset.cpp : 定义控制台应用程序的入口点。
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
		m_nTop = -1;// 数组是从0开始的，初始化为-1比较合理。
	}
	~CStack()
	{
		delete [] m_data;
		m_data = NULL;
		m_nTop = -1;
	}

	void ClearStack()
	{
		m_nTop = -1; // 只需要把top改成-1即可，并不需要把内存释放
	}


	// 输出
	void visit(T c)
	{
		printf("%d ",c);
	}

	// 取栈顶元素
	T GetTop()
	{
		if (m_nTop == -1){
			return -1;
		}

		return m_data[m_nTop];
	}

	// 是否为空
	bool empty()
	{
		return (m_nTop == -1) ? true: false;
	}

	// 栈的长度
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

	// 进栈
	void push(T data)
	{
		if (m_nTop == MAXSIZE-1){
			return;
		}

		m_nTop++;
		m_data[m_nTop] = data;
	}

	// 出栈
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
	int m_nTop; // 控制栈顶位置的变量
};


int _tmain(int argc, _TCHAR* argv[])
{
	CStack<int> stack;

	// 3个元素进栈
	stack.push(1);
	stack.push(2);
	stack.push(3);

	int nLength = stack.size();
	printf("栈的大小：%d\n", nLength);

	bool result = stack.empty();
	printf("栈是否为空：%d\n", result);

	int topResult = stack.GetTop();
	printf("栈顶元素：%d\n", topResult);

	// 从栈底向栈顶打印
	stack.Traverse();

	// 从栈顶向栈底打印
	stack.Traverse_2();

	// 清空栈,如果清空栈之后再pop必然失败，切记。
	//stack.ClearStack();

	// 3个元素出栈
	int n1 = stack.pop();
	int n2 = stack.pop();
	int n3 = stack.pop();
	return 0;
}