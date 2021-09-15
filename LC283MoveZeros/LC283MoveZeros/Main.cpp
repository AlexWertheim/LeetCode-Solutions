#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void printVector(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
}

void moveZeroes(vector<int>& nums) 
{
	int len = nums.size();
	nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
	nums.resize(len);
}

int main()
{
	vector<int> nums = { 0, 1, 0, 3, 12, 1 };
	moveZeroes(nums);
	printVector(nums);
	return 0;
}