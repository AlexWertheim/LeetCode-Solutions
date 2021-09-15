#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int len = nums.size();
    int reds = 0, whites = 0;
    for (int i = 0; i < len; i++)
    {
        if (nums[i] == 0)
        {
            reds++;
        }
        else if (nums[i] == 1)
        {
            whites++;
        }
    }
    int j = 0;
    while (j < reds)
    {
        nums[j] = 0;
        j++;
    }
    while (j < (reds + whites))
    {
        nums[j] = 1;
        j++;
    }
    while (j < len)
    {
        nums[j] = 2;
        j++;
    }
}

int main()
{
    return 0;
}