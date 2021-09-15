#include<iostream>
#include<vector>

using namespace std;

vector<int> sub(vector<int>& nums, int n)
{
    vector<int> set;
    if (n == 0)
    {
        return set;
    }
    int i = 0;
    while (n)
    {
        if (n % 2 == 1)
        {
            set.push_back(nums[i]);
        }
        i++;
        n /= 2;
    }
    return set;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    int n = (1 << nums.size());
    for (int i = 0; i < n; i++)
    {
        subsets.push_back(sub(nums, i));
    }
    return subsets;
}

int main()
{
	return 0;
}