#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int n)
{
	return 0;
}

int firstBadVersion(int n) {
	if (isBadVersion(0)) // if the first version is bad, then we're done
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	int low = 0, high = n, key = (high + low)/2; // otherwise, set up binary search
	while(high - low > 1)
	{
		if (isBadVersion(key)) // if the version is bad, then this is our new upper bound in the binary search for the first bad version
		{
			high = key;
			key = (high + low) / 2;
		}
		else // the version is good, so this is our new lower bound
		{
			low = key;
			key = (high + low) / 2;
		}
	}
	return high;
}


int main()
{
	vector<int> nums = { 1, 3 };
	cout << searchInsert(nums, 1) << endl;
	return 0;
}