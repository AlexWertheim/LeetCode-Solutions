#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
}

int gcd(int x, int y)
{
	int r = 0;
	while (y != 0)
	{
		r = y;
		y = (x % r);
		x = r;
	}
	return x; 
}

void rotate(vector<int>& nums, int k) 
{
	int len = nums.size();
	int rot = (k % len);
	int newVal = 0, storedVal = 0; 
	int lastHit = gcd(len, rot), cycleLen = len/lastHit;
	int index = 0;
	for (int i = 0; i < lastHit; i++)
	{
		index = i;
		newVal = nums[index];
		for (int j = 0; j < cycleLen; j++)
		{
			index = ((index + rot) % len);
			storedVal = nums[index];
			nums[index] = newVal; 
			newVal = storedVal;
		}
	}
}


int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6 };
	rotate(nums, 100);
	printVector(nums);
	// cout << gcd(10, 3) << endl; 
	return 0;
}