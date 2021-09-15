#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printVector(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++) 
	{
		cout << nums[i] << " ";
	}
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	int len1 = nums1.size(), len2 = nums2.size();
	int i = 0;
	unordered_map<int, int> candidateNums;
	vector<int> intersection; 
	bool firstBigger = (len1 < len2);
	if (firstBigger)
	{
		while (i < len1)
		{
			candidateNums[nums1[i]]++;
			i++;
		}
	}
	else
	{
		while (i < len2)
		{
			candidateNums[nums2[i]]++;
			i++;
		}
	}
	if (firstBigger)
	{
		for (int j = 0; j < len2; j++)
		{
			if (candidateNums.count(nums2[j]) && candidateNums[nums2[j]] > 0)
			{
				intersection.push_back(nums2[j]);
				candidateNums[nums2[j]]--;
			}
		}
	}
	else
	{
		for (int j = 0; j < len1; j++)
		{
			if (candidateNums.count(nums1[j]) && candidateNums[nums1[j]] > 0)
			{
				intersection.push_back(nums1[j]);
				candidateNums[nums1[j]]--;
			}
		}
	}
	return intersection;
}

int main()
{
	vector<int> nums1 = {1, 2, 2, 2, 1}, nums2 = {2, 2};
	vector<int> intersection = intersect(nums1, nums2);
	printVector(intersection);
	return 0;
}