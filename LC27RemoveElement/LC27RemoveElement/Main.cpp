#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) 
{
	if (nums.empty())
	{
		return 0;
	}
	int i = 0, length = 0;
	while (i < nums.size())
	{
		length++;
		if (nums.at(i) == val)
		{
			nums.erase(nums.begin() + i);
			length--;
			i--;
		}
		i++;
	}
	return length;
}

void printVector(vector<int>& nums)
{
	int i = 0;
	while (i < nums.size())
	{
		cout << nums.at(i) << endl;
		i++;
	}
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	cout << "Length of nums is: " << removeElement(nums, 3) << endl;
	cout << "Nums is: " << endl;
	printVector(nums);
	return 0;
}