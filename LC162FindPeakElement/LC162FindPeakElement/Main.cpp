#include <iostream>
#include <vector>

using namespace std;

bool isPeak(vector<int>& nums, int k)
{
    if (nums[k] > nums[k - 1] && nums[k] > nums[k + 1])
    {
        return true;
    }
    return false;
}

int findPeakElement(vector<int>& nums) {
    int len = nums.size();
    if (len == 1)
    {
        return 0;
    }
    if (nums[0] > nums[1])
    {
        return 0;
    }
    else if (nums[len - 1] > nums[len - 2])
    {
        return len - 1;
    }
    int low = 0, high = len - 1, mid = (low + high) / 2;
    while (!isPeak(nums, mid))
    {
        if (nums[mid] < nums[mid - 1])
        {
            high = mid;
            mid = (low + high) / 2;
        }
        if (nums[mid] > nums[mid - 1])
        {
            low = mid;
            mid = (low + high) / 2;
        }
    }
    return mid;
}


int main()
{
    return 0;
}