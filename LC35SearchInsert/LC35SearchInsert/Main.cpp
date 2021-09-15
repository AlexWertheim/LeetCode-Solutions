#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
	int len = nums.size();
	int high = len-1, low = 0, key = (high+low)/2;
	bool deadlocked = 0;
	if (target > nums[high])
	{
		return len;
	}
	if (target < nums[low])
	{
		return 0;
	}
	while (low < high)
	{
		if (nums[key] == target)
		{
			return key;
		}
		if (deadlocked)
		{
			return high;
		}
		if ((high - low) == 1)
		{
			deadlocked = 1;
		}
		else if (nums[key] > target)
		{
			high = key;
			key = (high + low) / 2;
		}
		else 
		{
			low = key;
			key = ((high + low) / 2);
		}
		cout << "High is: " << high << endl;
		cout << "Low is: " << low << endl;
	}
}


int main()
{
	vector<int> nums = { 1, 3};
	cout << searchInsert(nums, 1) << endl;
	return 0;
}