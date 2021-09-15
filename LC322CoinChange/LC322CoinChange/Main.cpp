#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


// Implementation which does not avoid repeats; only optimization involves not subtracting denominations which exceed the remaining amount
int coinChange(vector<int>& coins, int amount) {
    if (amount == 0)
    {
        return 0;
    }
    sort(coins.begin(), coins.end());
    vector<int> change(amount + 1, amount + 2);
    change[amount] = 0;
    int maxCoin = coins.size() - 1;
    if (coins[0] > amount)
    {
        return -1;
    }
    for (int i = amount; i >= coins[0]; i--)
    {
        while (maxCoin != -1 && coins[maxCoin] > i)
        {
            maxCoin--;
        }
        if (change[i] != (amount + 2))
        {
            for (int j = 0; j <= maxCoin; j++)
            {
                change[i - coins[j]] = min(change[i - coins[j]], change[i] + 1);
            }
        }
    }
    if (change[0] == (amount + 2))
    {
        return -1;
    }
    return change[0];
}


// Monotonic?

int coinChange(vector<int>& coins, int amount) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (amount == 0)
    {
        return 0;
    }
    sort(coins.begin(), coins.end());
    if (coins[0] > amount)
    {
        return -1;
    }
    vector<int> change(amount + 1, amount + 2);
    vector<int> maxC(amount + 1, 0);
    change[amount] = 0;
    maxC[amount] = coins.size() - 1;
    for (int i = amount; i >= coins[0]; i--)
    {
        if (change[i] != (amount + 2))
        {
            for (int j = 0; j <= maxC[i]; j++)
            {
                if (i - coins[j] > -1)
                {
                    change[i - coins[j]] = min(change[i - coins[j]], change[i] + 1);
                    maxC[i - coins[j]] = max(maxC[i - coins[j]], j);
                }
            }
        }
    }
    if (change[0] == (amount + 2))
    {
        return -1;
    }
    return change[0];
}

// another monic attempt? not sure what this is

int coinChange(vector<int>& coins, int amount) {
    if (amount == 0)
    {
        return 0;
    }
    sort(coins.begin(), coins.end());
    vector<int> change(amount + 1, amount + 2);
    change[amount] = 0;
    int maxCoin = coins.size() - 1;
    if (coins[0] > amount)
    {
        return -1;
    }
    for (int i = amount; i >= coins[0]; i--)
    {
        while (maxCoin != -1 && coins[maxCoin] > i)
        {
            maxCoin--;
        }
        if (change[i] != (amount + 2))
        {
            for (int j = 0; j <= maxCoin; j++)
            {
                change[i - coins[j]] = min(change[i - coins[j]], change[i] + 1);
            }
        }
    }
    if (change[0] == (amount + 2))
    {
        return -1;
    }
    return change[0];
}

int main()
{
    return 0;
}