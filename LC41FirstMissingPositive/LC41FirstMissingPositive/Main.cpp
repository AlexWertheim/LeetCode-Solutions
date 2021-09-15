#include <iostream>
#include <vector>

using namespace std;



int firstMissingPositive(vector<int>& nums)
{
	if (nums.empty())
	{
		return 1;
	}
	int len = nums.size();
	int posInts[300];
	for (int i = 0; i < 300; i++)
	{
		posInts[i] = 0;
	}
	for (int j = 0; j < len; j++)
	{
		if (nums[j] > 0 && nums[j] < 301)
		{
			posInts[nums[j] - 1] = 1;
		}
	}
	for (int i = 0; i < 300; i++)
	{
		if (!posInts[i])
		{
			return i + 1;
		}
	}
	return 301;
}

int main()
{
	// vector<int> nums = { -100, 50, 1, 13, 10 };
	// cout << firstMissingPositive(nums) << endl;
	bool a[300];
	cout << sizeof(a) << endl;
	return 0;
}