
#include "stdafx.h"
#include <vector>
#include <unordered_map>
using namespace std;

// 测试push
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int,int> order_map; // 使用unordered_map，内部hash实现
		vector<int> result(2);// 注意vector的构造函数的赋值含义，具体查看vector.h文件，常用的两个构造函数(1)初始化空间；(2)初始化空间并赋值
		for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
		{
			if (order_map.count( target - *iter))
			{
				result.push_back(order_map[target - *iter]);
				result.push_back(iter - nums.begin());
				return result;
			}

			order_map[*iter] = (int)(iter - nums.begin()); 
		}

		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(11);
	vec.push_back(15);

	Solution ddd;
	vector<int> rel = ddd.twoSum(vec, 88);
	return 0;
}