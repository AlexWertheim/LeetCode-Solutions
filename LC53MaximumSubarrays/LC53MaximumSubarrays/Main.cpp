#include <iostream>
#include <vector>

using namespace std;

// Idea: you can only increase the sum of a contiguous region by adding elements to it if the sum of those elements is positive.
// Therefore, starting at the left, we can keep expanding the region until our sum dips below 0. Once the running sum is < 0, 
// start our contiguous region over, since expanding leftwards can only decrease the sum.

int maxSubArray(vector<int>& nums)
{
	int currSum = nums[0], maxSum = nums[0]; // two variables: one to keep track of the maximum sum, one to keep track of the current sum; note that 
											 // maxSum must be initialized to nums[0], since the maximum may be negative
	int i = 1, len = nums.size();
	while (i < len)
	{
		if (currSum < 0) 
		{
			currSum = 0;
		}
		currSum += nums[i];
		if (currSum > maxSum)
		{
			maxSum = currSum;
		}
		i++;
	}
	return maxSum;
}

int main()
{
	vector<int> nums = {14, 2, -1, -2, 2, 15, -2, 1, 4, -5, 4};
	cout << maxSubArray(nums) << endl;
	return 0;
}