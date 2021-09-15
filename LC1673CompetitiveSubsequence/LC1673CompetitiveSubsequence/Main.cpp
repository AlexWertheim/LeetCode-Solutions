#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;


void printVector(vector<int>& nums)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << " ";
	}
}


int max(int x, int y)
{
	return (x < y) * y + (x >= y) * x;
}

vector<int> mostCompetitive(vector<int>& nums, int k)
{
	int len = nums.size();
	if (len == k)
	{
		return nums;
	}
	list<int> nums2(nums.begin(), nums.begin() + len);
	list<int>::iterator it = nums2.begin();
	while (len > k && (it != nums2.end())) 
	{
		cout << "iterator is: " << *it << endl;
		if (*it > *next(it))
		{
			if (it == nums2.begin())
			{
				nums2.pop_front();
				len--;
				it = nums2.begin();
			}
			else
			{
				it = prev(it);
				nums2.erase(next(it));
				len--;
			}
		}
		else
		{
			it++;
		}
	}
	while (len > k)
	{
		nums2.pop_back();
		len--;
	}
	vector<int> nums3(nums2.begin(), nums2.end());
	return nums3;
}




int main()
{
	vector<int> nums = {18,52,29,55,73,24,42,66,8,80,2};
	/* for (int i = 1; i < 10000; i++)
	{
		nums.push_back(1);
	} */ 
	vector<int> comp = mostCompetitive(nums, 3);
	printVector(comp);
	return 0;
}