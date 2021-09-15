#include <iostream>
#include <vector>

using namespace std;

// Potential problems with integer overflow, but otherwise simple: subtract min from each entry, then sum
// Why sum and then subtract min entry? Say they're sorted, for simplicity. The algorithm is:
// Bring a_1 up to a_n, modifying the first n-1 entries. The distance between a_1 and a_2, ..., a_{n-1} is the same,
// so now bring a_1 up to a_{n-1}, and so on. This is the strategy involving the minimum number of moves! Indeed,
// each of these moves *has* to be made in some ''order'', no matter how you select the n-1 remaining entries, since
// you always have to bridge the gap between the minimum entry and all other entries.
int minMoves(vector<int>& nums) {
    int res = 0, min = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        res += nums[i];
        if (nums[i] < min)
        {
            min = nums[i];

        }
    }
    return res - (nums.size() * min);
}

/*
// This one handles potential overflow better! More complicated though.
int minMoves(vector<int> & nums) {
int res = 0, min = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            res += abs(nums[i]-min);
            if(nums[i] < min)
            {
                res += (i-1)*(min-nums[i]);
                min = nums[i];

            }
        }
}
*/

int main()
{
    return 0;
}