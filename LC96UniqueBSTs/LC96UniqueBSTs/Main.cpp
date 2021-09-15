#include<iostream>
#include<unordered_map>

using namespace std;

int numBSTs(int n, unordered_map<int, int>& trees)
{
    if (trees.count(n))
    {
        return trees[n];
    }
    else
    {
        if (n == 0)
        {
            trees[0] = 1;
        }
        for (int k = 1; k <= n; k++)
        {
            trees[n] += (numBSTs(k - 1, trees) * numBSTs(n - k, trees));
        }
        return trees[n];
    }
}

int numTrees(int n) {
    unordered_map<int, int> trees;
    return numBSTs(n, trees);
}