// TestHash.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <functional>


struct S {
	std::string first_name;
	std::string last_name;
};

namespace std {
	template<>
	class hash<S> {
	public:
		size_t operator()(const S &s) const
		{
			size_t h1 = std::hash<std::string>()(s.first_name);
			size_t h2 = std::hash<std::string>()(s.last_name);
			return h1 ^ ( h2 << 1 );
		}
	};
}



int _tmain(int argc, _TCHAR* argv[])
{
	// hash函数，key为std::string
	std::string s = "Stand back! I've got jimmies!"; //key
	std::hash<std::string> hash_fn; // hash 函数
	size_t hash = hash_fn(s); // value
	
	// hash函数，key为int
	std::hash<int> hasher; // hash 函数
	size_t hash1 = hasher(1);
	size_t hash2 = hasher(2);
	size_t hash3 = hasher(3);
	size_t hash4 = hasher(4);
	size_t hash5 = std::hash<int>()(5); // std::hash<int>()等同于std::hash<int> hasher;

	// 自定义hash [11/7/2018 hehuan]
	S s_1;
	s_1.first_name = "Bender";
	s_1.last_name =  "Rodriguez";
	std::hash<S> hash_fn_1;
	size_t hash6 = hash_fn_1(s_1);

	return 0;
}

