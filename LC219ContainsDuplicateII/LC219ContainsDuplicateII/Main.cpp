#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> distinctNums;
	int len = nums.size(), i = 0;
	while (i < len)
	{
		if (distinctNums.count(nums[i]) && (abs(distinctNums[nums[i]] - i) <= k))
		{
			return 1;
		}	
		else
		{
			distinctNums[nums[i]] = i;
			i++;
		}
	}
	return 0;
}

int main()
{
	vector<int> nums = { 1,2, 3, 4, 5, 1, 2};
	if (containsNearbyDuplicate(nums, 5))
	{
		cout << "Has nearby duplicates!" << endl;
	}
	else
	{
		cout << "No nearby duplicates!" << endl;
	}
	return 0;
}