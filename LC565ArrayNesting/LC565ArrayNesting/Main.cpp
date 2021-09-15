#include<iostream>
#include<vector>

using namespace std;

int cycleLength(vector<int>& nums, vector<int>& visited, int n)
{
    int len = 0;
    while (!visited[n])
    {
        visited[n] = 1;
        n = nums[n];
        len++;
    }
    return len;
}

int arrayNesting(vector<int>& nums) {
    vector<int> visited(nums.size(), 0);
    int max = 1;
    int cycleLen = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!visited[i])
        {
            cycleLen = cycleLength(nums, visited, i);
            if (cycleLen > max)
            {
                max = cycleLen;
            }
        }
    }
    return max;
}

int main()
{
    return 0;
}