#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxStreak = 0, currStreak = 0;
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] == 0)
        {
            maxStreak = max(maxStreak, currStreak);
            currStreak = 0;
        }
        else
        {
            currStreak++;
        }
        i++;
    }
    return max(maxStreak, currStreak);
}

int main()
{
    return 0;
}