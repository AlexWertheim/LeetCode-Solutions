#include<iostream>
#include<vector>

using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustworthy(n, 0);
    vector<bool> trusting(n, 0);
    for (int i = 0; i < trust.size(); i++)
    {
        trusting[trust[i][0] - 1] = 1;
        trustworthy[trust[i][1] - 1]++;
    }
    for (int j = 0; j < n; j++)
    {
        if (trustworthy[j] == (n - 1) && !trusting[j])
        {
            return j + 1;
        }
    }
    return -1;
}

int main()
{
    return 0;
}