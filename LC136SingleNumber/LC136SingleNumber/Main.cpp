#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int uniqueNum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		uniqueNum = uniqueNum^nums[i]; 
	}
	return uniqueNum;
}

int main()
{
	vector<int> nums = { 4, 2, 3, 2, 3 };
	cout << singleNumber(nums) << endl;
	return 0;
}