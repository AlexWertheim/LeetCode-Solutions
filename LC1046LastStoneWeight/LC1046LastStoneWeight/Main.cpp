#include<iostream>
#include<queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> orderedStones;
    for (int i = 0; i < stones.size(); i++)
    {
        orderedStones.push(stones[i]);
    }
    int b = 0, s = 0;
    while (orderedStones.size() > 1)
    {
        b = orderedStones.top();
        orderedStones.pop();
        s = orderedStones.top();
        orderedStones.pop();
        if (b != s)
        {
            orderedStones.push(b - s);
        }
    }
    if (orderedStones.empty())
    {
        return 0;
    }
    return orderedStones.top();
}

int main()
{
    return 0;
}