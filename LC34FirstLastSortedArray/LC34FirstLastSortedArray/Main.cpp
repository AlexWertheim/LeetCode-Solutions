#include <iostream>
#include <vector>

using namespace std;

int searchElt(vector<int>& nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int guess = (low + high) / 2;
    while (low <= high)
    {
        if (nums[guess] == target)
        {
            return guess;
        }
        else if (nums[guess] < target)
        {
            low = guess + 1;
            guess = (low + high) / 2;
        }
        else
        {
            high = guess - 1;
            guess = (low + high) / 2;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range(2, -1);
    int foundPos = searchElt(nums, target);
    if (foundPos == -1)
    {
        return range;
    }
    int lowLB = 0, highLB = foundPos;
    int lowUB = foundPos, highUB = nums.size() - 1;
    int lowR = (lowLB + highLB) / 2, highR = (lowUB + highUB) / 2;
    while (lowLB <= highLB)
    {
        if (nums[lowR] < target)
        {
            lowLB = lowR + 1;
            lowR = (lowLB + highLB) / 2;
        }
        else
        {
            highLB = lowR - 1;
            lowR = (lowLB + highLB) / 2;
        }
    }
    cout << lowLB << endl;
    while (lowUB <= highUB)
    {
        if (nums[highR] > target)
        {
            highUB = highR - 1;
            highR = (lowUB + highUB) / 2;
        }
        else
        {
            lowUB = highR + 1;
            highR = (lowUB + highUB) / 2;
        }
    }
    range[0] = lowLB;
    range[1] = highUB;
    return range;
}

int main()
{
    return 0;
}