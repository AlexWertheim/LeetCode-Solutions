#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int minVal = nums[0], streakVal = nums[0];
    bool firstStreak = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > minVal && nums[i] <= streakVal)
        {
            streakVal = nums[i];
            firstStreak = 0;
        }
        else if (nums[i] > streakVal && firstStreak)
        {

            streakVal = nums[i];
            firstStreak = 0;
        }
        else if (nums[i] > streakVal)
        {
            return true;
        }
        else if (nums[i] < minVal)
        {
            minVal = nums[i];
        }
    }
    return false;
}

int main()
{
	return 0;
}