#include<iostream>
#include<vector>

using namespace std;

void reverseNums(vector<int>& nums, int m, int n)
{
    int temp = 0;
    while (m < n)
    {
        temp = nums[m];
        nums[m] = nums[n];
        nums[n] = temp;
        m++;
        n--;
    }
}



void nextPermutation(vector<int>& nums) {
    int j = nums.size() - 1;
    while (j > 0 && nums[j - 1] >= nums[j])
    {
        j--;
    }
    if (j == 0)
    {
        reverseNums(nums, 0, nums.size() - 1);
        return;
    }
    int i = j, min = nums[i];
    int k = i;
    while (i < nums.size() - 1)
    {
        i++;
        if (nums[i] <= min && nums[i] > nums[j - 1])
        {
            min = nums[i];
            k = i;
        }
    }
    int temp = nums[j - 1];
    nums[j - 1] = nums[k];
    nums[k] = temp;
    reverseNums(nums, j, nums.size() - 1);
}

int main()
{
    return 0;
}