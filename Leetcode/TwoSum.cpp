
#include "stdafx.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int,int> order_map; // ʹ��unordered_map���ڲ�hashʵ��
		vector<int> result(2);// ע��vector�Ĺ��캯���ĸ�ֵ���壬����鿴vector.h�ļ������õ��������캯��(1)��ʼ���ռ䣻(2)��ʼ���ռ䲢��ֵ
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