#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int maxRob(vector<int>& nums, unordered_map<int, int>& lastHouse, int len)
{
    if (lastHouse.count(len))
    {
        return lastHouse[len];
    }
    else
    {
        if (len == 0)
        {
            return 0;
        }
        else if (len == 1)
        {
            lastHouse[1] = nums[0];
            return lastHouse[1];
        }
        else if (len == 2)
        {
            lastHouse[2] = max(nums[0], nums[1]);
            return lastHouse[2];
        }

        else
        {
            lastHouse[len] = max(nums[len - 1] + maxRob(nums, lastHouse, len - 2),
                nums[len - 2] + maxRob(nums, lastHouse, len - 3));
            return lastHouse[len];
        }
    }

}


int rob(vector<int>& nums) {
    int len = nums.size();
    unordered_map<int, int> lastHouse;
    return maxRob(nums, lastHouse, len);
}

int main()
{
    return 0;
}