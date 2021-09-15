#include <iostream>
#include <vector>

using namespace std;

int counter = 0;

int max(int x, int y)
{
	return (x < y) * y + (x >= y) * x;
}

int maximumScore(vector<int>& nums, vector<int>& multipliers) 
{
	counter++;
	cout << "counter is: " << counter << endl; 
	int m = multipliers.size(), n = nums.size();
	if (m == 1)
	{
		return max((multipliers[0] * nums[0]), (multipliers[0] * nums[n - 1])); 
	}
	else
	{
		vector<int> numsF(nums.begin(), nums.begin() + (n - 1));
		vector<int> numsL(nums.begin() + 1, nums.begin() + n);
		vector<int> newMult(multipliers.begin() + 1, multipliers.begin() + m);
		return max(((multipliers[0] * nums[0]) + maximumScore(numsL, newMult)), ((multipliers[0] * nums[n - 1]) + maximumScore(numsF, newMult)));
	}
}

int main()
{
	// vector<int> nums = { 555, 526, 732, 182, 43, -537, -434, -233, -947, 968, -250, -10, 470, -867, -809, -987, 120, 607, -700, 25, -349, -657, 349, -75, -936, -473, 615, 691, -261, -517, -867, 527, 782, 939, -465, 12, 988, -78, -990, 504, -358, 491, 805, 756, -218, 513, -928, 579, 678, 10 };
	// vector<int> multipliers = { 783, 911, 820, 37, 466, -251, 286, -74, -899, 586, 792, -643, -969, -267, 121, -656, 381, 871, 762, -355, 721, 753, -521 };
	vector<int> nums = { -5,-3,-3,-2,7,1 };
	vector<int> multipliers = { -10,-5,3,4,6 };
	cout << maximumScore(nums, multipliers) << endl;
	return 0;
}