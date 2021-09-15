#include <iostream>
#include <vector>

using namespace std;

int max(int x, int y)
{
	return (x > y) * x + (x <= y) * y;
}

/* Solution 1: 

bool canJump(vector<int>& nums) 
{
	if (nums.size() == 1) // if only trivial steps to be taken, return true
	{
		return 1;
	}
	if (nums[0] == 0) // no steps can be taken, sadge
	{
		return 0;
	}
	else 
	{
		nums[1] = max(nums[1],  (nums[0] - 1));
		nums.erase(nums.begin());
		return canJump(nums);
	}

}*/

// Solution 2 - faster, removes recursive dependence on erase/size!

bool canJump(vector<int>& nums)
{
	int len = nums.size(); // initialize length of nums
	if (len == 1) // if only trivial steps to be taken, return true
	{
		return 1;
	}
	int i = 0;
	while (i < len-1)
	{
		if (nums[i] == 0) // no steps can be taken, sadge
		{
			return 0;
		}
		else 
		{
			nums[i+1] = max(nums[i+1], (nums[i] - 1));
			i++;
		}
	}
	return 1;
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	if (canJump(nums))
	{
		cout << "Failure!" << endl;
	}
	else
	{
		cout << "Success!" << endl;
	}
	return 0;
}