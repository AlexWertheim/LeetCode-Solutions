#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Cheeky solution
// The majority element must be the median, so it's enough to find the median of the unsorted array in linear time.     
int majorityElement(vector<int>& nums) {
    int halfLen = (nums.size() / 2);
    const size_t k = halfLen;
    nth_element(nums.begin(), nums.begin() + k, nums.end()); // QuickSelect the kth element
    return nums[k];
}*/

// Clever solution using Boyer-Moore voting algorithm
int majorityElement(vector<int>& nums) {
    int majorityElt = nums[0];
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == majorityElt)
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count < 0)
        {
            majorityElt = nums[i];
            count = 0;
        }
    }
    return majorityElt;
}

int main()
{
	return 0;
}