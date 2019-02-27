// TestPailie.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& vec, int i, int j)
{
	int tmp = vec[i];
	vec[i] =  vec[j];
	vec[j] = tmp;
}

//0~s-1, s~n-1
void perm(vector<int> vec, int s, int n)
{
	if(s >= n)
	{
		for(int i = 0; i < n; i++)
		{
			cout << vec[i] << "���,";
		}
		cout << endl;
	}
	else
	{
		for(int i = s; i < n; i++)
		{
			swap(vec, s, i);
			for(int j = 0; j < n; j++)
			{
				cout <<vec[j] << ",";
			}
			cout << endl;
			perm(vec, s+1, n);
			swap(vec, s, i);
			for(int k = 0; k < n; k++)
			{
				cout << vec[k] << "����,";
			}
			cout << endl;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	for(int i = 0; i < 3; i++)
	{
		vec.push_back(i+1);
	}
	perm(vec, 0, 3);
	return 0;

	return 0;
}

