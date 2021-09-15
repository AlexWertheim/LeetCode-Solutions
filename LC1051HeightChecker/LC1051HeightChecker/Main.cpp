#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> expected = heights;
    sort(heights.begin(), heights.end());
    int unexpected = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] != expected[i])
        {
            unexpected++;
        }
    }
    return unexpected;
}

int main()
{
    return 0;
}