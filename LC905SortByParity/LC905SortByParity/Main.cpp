#include <iostream>
#include <vector>

using namespace std;

bool isOdd(int n)
{
    return ((n % 2) == 1);
}

vector<int> sortArrayByParity(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;
    int temp = 0;
    while (i < j)
    {
        if (isOdd(nums[i]) && !(isOdd(nums[j])))
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        if (!isOdd(nums[i]))
        {
            i++;
        }
        if (isOdd(nums[j]))
        {
            j--;
        }
    }
    return nums;
}

int main()
{
    return 0;
}