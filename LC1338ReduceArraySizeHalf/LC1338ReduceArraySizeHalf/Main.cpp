#include<iostream>
#include<vector>
#include<unordered_map>
#include<priority_queue>
#include<algorithm>

using namespace std;

/* Same as array solution, but sorts instead of using priority queue
int minSetSize(vector<int>& arr) {
    vector<int> counts(100001, 0);
    int len = arr.size();
    int halfLen = len / 2;
    for (int i = 0; i < len; i++)
    {
        counts[arr[i]]++;
    }
    sort(counts.begin(), counts.end());
    int setSize = 0, e = counts.size() - 1;
    while (len > halfLen)
    {
        len -= counts[e];
        e--;
        setSize++;
    }
    return setSize;
}*/

// Uses size of elements of arr to implement faster access version which uses more memory. Priority queue for sorting. 

int minSetSize(vector<int>& arr) {
    vector<int> counts(100001, 0);
    int len = arr.size();
    int halfLen = len / 2;
    for (int i = 0; i < len; i++)
    {
        counts[arr[i]]++;
    }
    // priority_queue<int> sortedCounts;
    for (auto x : counts)
    {
        sortedCounts.push(x);
    }
    int setSize = 0, maxS = sortedCounts.top();
    while (len > halfLen)
    {
        len -= maxS;
        sortedCounts.pop();
        maxS = sortedCounts.top();
        setSize++;
    }
    return setSize;
}

/*  // Hash map solution; slower because larger access times, but uses significantly less memory
    int minSetSize(vector<int>& arr) {
    unordered_map<int, int> counts;
    int len = arr.size();
    int halfLen = len/2;
    for(int i = 0; i < len; i++)
    {
        counts[arr[i]]++;
    }
    vector<int> sortedCounts;
    for(auto x : counts)
    {
        sortedCounts.push_back(x.second);
    }
    sort(sortedCounts.begin(), sortedCounts.end());
    int setSize = 0, e = sortedCounts.size()-1;
    while(len > halfLen)
    {
        len -= sortedCounts[e];
        setSize++;
        e--;
    }
    return setSize;
}*/

int main()
{
	return 0;
}