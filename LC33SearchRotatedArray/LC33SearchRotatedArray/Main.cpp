#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int mid, prev, next;
    int len = nums.size();
    int max = 2 * (len - 1) + 1;
    int min = 0;
    bool notFound = 1;
    int prevNum;
    bool right = 1;
    while (notFound)
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
            notFound = 0;
            min = mid + 1;
            max = mid + len;
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
    if (min >= len)
    {
        min -= len;
        max -= len;
    }
    while (min < max)
    {
        mid = ((min + max) / 2);
        if (nums[mid % len] == target)
        {
            return mid % len;
        }
        else if (nums[mid % len] < target)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    if (nums[min % len] == target)
    {
        return min % len;
    }
    else
    {
        return -1;
    }
}

int main()
{
    return 0;
}