#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

void printVector(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
}

/* Slow: uses erase. 
int removeDuplicates(vector<int>& nums) 
{
	int len = nums.size(), i = 0;
	while (i < len-1)
	{
		if (nums[i] == nums[i + 1])
		{
			nums.erase((nums.begin() + (i + 1)));
			len--;
		}
		else
		{
			i++;
		}
	}
	printVector(nums);
	return len;
}*/



int removeDuplicates(vector<int>& nums)
{
	vector<int>::iterator toRemove;
	toRemove = unique(nums.begin(), nums.end());
	nums.resize(distance(nums.begin(), toRemove));
	printVector(nums);
	cout << endl;
	return nums.size();
}

int main()
{
	vector<int> nums = { 1, 2, 3, 4, 4, 5};
	cout << removeDuplicates(nums) << endl;
	return 0;
}