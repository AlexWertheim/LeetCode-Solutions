#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
	unordered_map<int, bool> distinctNums;
	int len = nums.size(), i = 0;
	while (i < len)
	{
		if (distinctNums.count(nums[i]))
		{
			return 1;
		}
		else
		{
			distinctNums[nums[i]] = 1;
			i++;
		}
	}
	return 0;
}

int main()
{
	vector<int> nums = { 1,2, 3, 4, 5};
	if (containsDuplicate(nums))
	{
		cout << "Has duplicates!" << endl;
	}
	else
	{
		cout << "All distinct!" << endl;
	}
	return 0;
}