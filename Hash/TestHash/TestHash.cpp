// TestHash.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <functional>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string s = "Stand back! I've got jimmies!"; //key
	std::hash<std::string> hash_fn; // hash 函数
	size_t hash = hash_fn(s); // value
	std::cout << hash << '\n';
	return 0;
}

