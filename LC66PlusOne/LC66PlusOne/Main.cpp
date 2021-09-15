#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " "; 
	}
}

vector<int> plusOne(vector<int>& digits) 
{
	bool carry = true;
	int len = digits.size(), i = len-1;
	while (carry && i > -1)
	{
		if (digits[i] + 1 < 10)
		{
			digits[i]++;
			carry = false;
		}
		else
		{
			digits[i] = 0;
			i--;
		}
	}
	if (i == -1)
	{
		digits.push_back(0);
		digits[0] = 1;
	}
	return digits;
}

int main()
{
	vector<int> digits = { 9, 9, 9 };
	plusOne(digits);
	printVector(digits);
	return 0;
}