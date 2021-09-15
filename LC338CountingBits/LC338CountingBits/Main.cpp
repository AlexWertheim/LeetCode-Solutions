#include<iostream>
#include<vector>

using namespace std;

/*
// Clever method using dynamic programming
vector<int> countBits(int n) {
    vector<int> bin(1, 0);
    int currPow = 1; // current power;
    int nextPow = currPow << 1; // next power;
    for (int i = 1; i <= n; i++)
    {
        bin.push_back(bin[i % currPow] + 1);
        if (i == nextPow)
        {
            currPow = nextPow;
            nextPow = currPow << 1;
        }
    }
    return bin;
}*/

// Clever*er* method using dynamic programming!!
vector<int> countBits(int n) {
    vector<int> bin(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            bin.push_back(bin[i / 2]);
        }
        if (i % 2 == 1)
        {
            bin.push_back(bin[i / 2] + 1);
        }
    }
    return bin;
}

int main()
{
    return 0;
}
