#include<iostream>
#include<vector>

using namespace std;

int findMin(vector<int>& nums) {
    int mid, prev, next;
    int len = nums.size();
    int max = 2 * (len - 1) + 1;
    int min = 0;
    int prevNum = -5001;
    bool right = 1;
    while (1)
    {
        mid = ((min + max) / 2);
        prev = (mid - 1) % len;
        next = (mid + 1) % len;
        if (prevNum > nums[mid % len])
        {
            right = 0;
        }
        else
        {
            right = 1;
        }
        if (nums[mid % len] >= nums[prev] && nums[mid % len] >= nums[next]) // if maximum
        {
            return nums[(mid + 1) % len];
        }
        else
        {
            if (right)
            {
                min = mid + 1;
            }
            else
            {
                max = mid - 1;
            }
        }
        prevNum = nums[mid % len];
    }
}

int main()
{
    return 0;
}