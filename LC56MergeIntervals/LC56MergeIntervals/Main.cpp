#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Can be modestly improved by dispensing with i, j.
// go through the contents of intervals:
// if mergedInts is empty or the right endpoint of the last entry is less 
// than the left endpoint of the current element of intervals, then just add it.
// otherwise, replace the [1] element of the last entry of mergedInts with the 
// maximum of the right endpt of the interval to be added, and the current right endpt

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedInts;
    sort(intervals.begin(), intervals.end()); // this sorts by first entry
    int len = intervals.size();
    int i = 0, j = 1;
    int leftEnd = intervals[0][0];
    int rightEnd = intervals[0][1];
    while (j < len)
    {
        if (rightEnd >= intervals[j][0]) // if right endpoint > left end point 
        {
            rightEnd = max(intervals[j][1], rightEnd);
            j++;
        }
        else
        {
            mergedInts.push_back({ leftEnd, rightEnd });
            i = j;
            leftEnd = intervals[i][0];
            rightEnd = intervals[i][1];
            j++;
        }
    }
    mergedInts.push_back({ leftEnd, rightEnd });
    return mergedInts;
}


int main()
{
	return 0;
}