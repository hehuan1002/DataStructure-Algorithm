// TestReverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

#define LEN  5
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int* num = new int[m+n];
		int i = 0, j = 0, k = 0;
		while (i < m && j < n)
		{
			if (nums1[i] < nums2[j])
				num[k++] = nums1[i++];
			else
				num[k++] = nums2[j++];
		}

		while (i < m) num[k++] = nums1[i++];
		while (j < n) num[k++] = nums2[j++];

		std::copy(num, num+m+n,nums1.begin());

		delete [] num;
		num = NULL;
	}

	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int k = m+n;
		while (m > 0 && n > 0)
		{
			if (nums1[m-1] < nums2[n-1])
			{
				nums1[k-1] = nums2[n-1];
				k--;
				n--;
			}
			else
			{
				nums1[k-1] = nums1[m-1];
				k--;
				m--;
			}
		}

		while (n > 0)
		{
			nums1[k-1] = nums2[n-1];
			k--;
			n--;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{	
	vector<int> nums1;
	nums1.push_back(4);
	nums1.push_back(5);
	nums1.push_back(6);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);

	vector<int> nums2;
	nums2.push_back(1);
	nums2.push_back(2);
	nums2.push_back(3);

	Solution sln;
	//sln.merge(nums1, 3, nums2, 3);
	sln.merge2(nums1, 3, nums2, 3);

	return 0;
}