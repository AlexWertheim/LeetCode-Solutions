#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// There is a beautiful, simpler greedy approach, but I like this one too

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedInts;
    int len = intervals.size();
    int i = 0, j = 1;
    int leftEnd = intervals[0][0];
    int rightEnd = intervals[0][1];
    while (j < len)
    {
        if (rightEnd > intervals[j][0]) // if right endpoint > left end point 
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

vector<int> partitionLabels(string s) {
    unordered_map<char, vector<int>> positions;
    vector<char> distinctChars;
    vector<vector<int>> intervals;
    for (int i = 0; i < s.length(); i++)
    {
        if (positions.count(s[i]))
        {
            positions[s[i]][1] = i;
        }
        else
        {
            positions[s[i]] = { i, i };
            distinctChars.push_back(s[i]);
        }
    }
    for (int i = 0; i < distinctChars.size(); i++)
    {
        intervals.push_back({ positions[distinctChars[i]][0], positions[distinctChars[i]][1] });
        // cout  << intervals[i][0] << ", " << intervals[i][1] << endl;
    }
    intervals = merge(intervals);
    vector<int> partitions(1, intervals[0][1] + 1);
    for (int i = 1; i < intervals.size(); i++)
    {
        partitions.push_back(intervals[i][1] - intervals[i - 1][1]);
    }
    return partitions;
}


int main()
{
	return 0;
}