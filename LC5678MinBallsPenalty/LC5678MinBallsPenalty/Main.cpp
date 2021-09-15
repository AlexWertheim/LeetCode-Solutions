#include <iostream>
#include <vector>

using namespace std;


void printVector(vector<int>& nums)
{
	int i = 0, len = nums.size();
	while (i < len)
	{
		cout << nums[i] << " ";
		i++;
	}
}

int findMax(vector<int> nums)
{
	int max = nums[0], i = 1, len = nums.size();
	while (i < nums.size())
	{
		if (nums[i] > max)
		{
			max = nums[i];
		}
		i++;
	}
	return max;
}

int findMaxPos(vector<int> nums)
{
	if (nums.empty())
	{
		return -1;
	}
	int max = nums[0], i = 1, len = nums.size(), maxPos = 0;
	while (i < nums.size())
	{
		if (nums[i] > max)
		{
			max = nums[i];
			maxPos = i;
		}
		i++;
	}
	return maxPos;
}

int minimumSize(vector<int>& nums, int maxOperations)
{
	int i = 0, j = 0, min = nums[0], len = nums.size(), maxVali = nums[0], maxValj = nums[0];
	while (maxOperations > 0)
	{
		i = findMaxPos(nums);
		maxVali = nums[i];
		if(maxVali == 1)
		{
			printVector(nums);
			return 1;
		}
		nums.erase(nums.begin()+i);
		j = findMaxPos(nums);
		if (j == -1)
		{
			if (maxOperations == 1)
			{
				nums.push_back(maxVali / 2);
				nums.push_back((maxVali - (maxVali / 2)));
				maxOperations--;
				/* cout << "maxOperations is: " << maxOperations << endl;
				printVector(nums);
				cout << endl; */
			}
			else
			{
				nums.push_back(maxVali / 3);
				nums.push_back((maxVali - (maxVali / 3)));
				maxOperations--;
			}
		}
		else
		{
			maxValj = nums[j];
			if (maxVali / 2 < maxValj || maxOperations == 1)
			{
				nums.push_back(maxVali / 2);
				nums.push_back((maxVali - (maxVali / 2)));
				maxOperations--;
			}
			else
			{
				nums.push_back(maxValj);
				nums.push_back((maxVali - maxValj));
				maxOperations--;
			}
		}
	}
	printVector(nums);
	min = findMax(nums);
	return min;
}

int main()
{
	// vector<int> nums = { 431, 922, 158, 60, 192, 14, 788, 146, 788, 775, 772, 792, 68, 143, 376, 375, 877, 516, 595, 82, 56, 704, 160, 403, 713, 504, 67, 332, 26 };
	// cout << findMax(nums) << endl;
	vector<int> nums = {7, 17};
	cout << endl << minimumSize(nums, 2) << endl;
	return 0;
}