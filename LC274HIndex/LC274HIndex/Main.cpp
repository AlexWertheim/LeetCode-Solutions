#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/* // Slower method using sorting
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0;
        int papers = citations.size();
        if(citations[0] >= papers)
        {
            return papers;
        }
        for(int i = papers-1; i > 0; i--)
        {
            if(citations[i] >= (papers-i) && citations[i-1] <= (papers-i))
            {
                h = (papers-i);
            }
        }
        return h;
    }*/

int hIndex(vector<int>& citations) {
    int papers = citations.size();
    vector<int> index(papers + 1, 0);
    for (int i = 0; i < papers; i++)
    {
        if (citations[i] < papers)
        {
            index[citations[i]]++;
        }
        else
        {
            index[papers]++;
        }
    }
    int sum = 0;
    for (int j = papers; j > -1; j--)
    {
        sum += index[j];
        if (sum >= j)
        {
            return j;
        }
    }
    return 0;
}

int main()
{
    return 0;
}