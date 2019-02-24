#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		size_t size = nums.size();
		vector<vector<int>> result;
		for (int i = 0; i < size; i++)
		{
			int left = i+1;
			int right = size - 1;
			while(left < right)
			{
				if (nums[i] + nums[left] + nums[right] > 0)
				{
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0)
				{
					left++;
				}
				else
				{
					vector<int> va;
					va.push_back(nums[i]);
					va.push_back(nums[left]);
					va.push_back(nums[right]);
					result.push_back(va);
					return result;
				}
			}
		}
	}
};