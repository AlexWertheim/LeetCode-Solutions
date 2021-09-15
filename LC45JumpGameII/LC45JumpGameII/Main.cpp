#include<iostream>
#include<vector>

using namespace std;

int jump(vector<int>& nums) {
    int len = nums.size();
    vector<int> minSteps(len, 0);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (j >= len)
        {
            break;
        }
        for (int k = j + 1; k <= min(len - 1, i + nums[i]); k++)
        {
            minSteps[k] = minSteps[i] + 1;
            // cout << min[k] << endl;
        }
        j = max(j, i + nums[i]);
    }
    return minSteps[len - 1];
}

int main()
{
    return 0;
}