#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*vector<int> merge(vector<int> sortedA, vector<int> sortedB)
{
	vector<int> merged;
	int a = 0, b = 0;
	int sizeA = sortedA.size(), sizeB = sortedB.size();
	bool aFinished = 0, bFinished = 0;
	while (!(aFinished || bFinished))
	{
		if (sortedA.at(a) <= sortedB.at(b))
		{

			merged.push_back(sortedA.at(a));
			a++;
		}
		else
		{
			merged.push_back(sortedB.at(b));
			b++;
		}
		aFinished = 1 * (a == sizeA);
		bFinished = 1 * (b == sizeB);
	}
	if (aFinished)
	{
		while (b < sizeB)
		{
			merged.push_back(sortedB.at(b));
			b++;
		}
	}
	if (bFinished)
	{
		while (a < sizeA)
		{
			merged.push_back(sortedA.at(a));
			a++;
		}
	}
	return merged;
}

vector<int> mergeSort(vector<int> nums)
{
	int len = nums.size();
	if (nums.size() > 1)
	{
		vector<int> halfOne;
		vector<int> halfTwo;
		int i = 0;
		while (i < len)
		{
			if (i < (len / 2))
			{
				halfOne.push_back(nums.at(i));
				i++;
			}
			else
			{
				halfTwo.push_back(nums.at(i));
				i++;
			}
		}
		return(merge(mergeSort(halfOne), mergeSort(halfTwo)));
	}
	else
	{
		return nums;
	}
}

Ugly solution using mergeSort

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> indices;
	vector<int> numsSorted = mergeSort(nums);
	int i = 0, j = numsSorted.size()-1;
	bool found = 0;
	while (!found)
	{
		if (numsSorted.at(i) + numsSorted.at(j) == target)
		{
			found = 1;
		}
		else if (numsSorted.at(i) + numsSorted.at(j) > target)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	for (int x = 0; x < nums.size(); x++)
	{
		if (nums.at(x) == numsSorted.at(i) || nums.at(x) == numsSorted.at(j))
		{
			indices.push_back(x);
		}
	}
	return indices;
} */

void printVector(vector<int>& nums)
{
	int i = 0;
	while (i < nums.size())
	{
		cout << nums.at(i) << endl;
		i++;
	}
}

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> candidates;
	vector<int> coordinates;
	int len = nums.size(), i = 0;
	{
		while (i < len)
		{
			if (candidates.count((target - nums[i])))
			{
				coordinates.push_back(candidates[target-nums[i]]);
				coordinates.push_back(i);
			}
			else
			{
				candidates[nums[i]] = i;
			}
			i++;
		}
	}
	return coordinates; 
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(15);
	vector<int> garbage = twoSum(nums, 6);
	printVector(garbage);
	return 0;
}