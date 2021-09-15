#include<iostream>
#include<vector>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int len = nums.size();
    vector<int> counts(len, 0);
    vector<int> result;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        counts[nums[i] - 1]++;
        if (counts[nums[i] - 1] == 2)
        {
            result.push_back(nums[i]);
        }
        sum += nums[i];
    }
    result.push_back(
        result[0] - sum + ((len * (len + 1)) / 2)
    );
    return result;
}

int main()
{
    return 0;
}