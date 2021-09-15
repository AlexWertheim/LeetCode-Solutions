#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> inserted;
    int len = intervals.size();
    int i = 0;
    int lEnd = newInterval[0], rEnd = newInterval[1];
    while (i < len && newInterval[0] > intervals[i][0])
    {
        inserted.push_back(intervals[i]);
        i++;
    }
    if (i > 0 && intervals[i - 1][1] >= newInterval[0]) // if overlap
    {
        lEnd = intervals[i - 1][0];
        inserted.pop_back();
        i--;
    }
    vector<int> merged = { lEnd };
    while (i < len && newInterval[1] > intervals[i][1])
    {
        i++;
    }
    if (i < len && newInterval[1] >= intervals[i][0]) // if overlap
    {
        rEnd = intervals[i][1];
        i++;
    }
    merged.push_back(rEnd);
    inserted.push_back(merged);
    while (i < len)
    {
        inserted.push_back(intervals[i]);
        i++;
    }
    return inserted;
}

// could also modify to just record left-most and right-most endpoints in "middle section" using maxes and mins. don't like that

int main()
{
    return 0;
}