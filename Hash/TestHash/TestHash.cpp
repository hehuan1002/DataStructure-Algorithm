// TestHash.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <functional>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string s = "Stand back! I've got jimmies!"; //key
	std::hash<std::string> hash_fn; // hash ����
	size_t hash = hash_fn(s); // value
	std::cout << hash << '\n';
	return 0;
}

