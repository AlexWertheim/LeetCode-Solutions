#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Can make code less complicated by keeping track of zeros at all positions, and updating iteratively
// also, apparently there is dynamic programming solution. good to come back to this and write one!

int minFlipsMonoIncr(string s) {
    int l = s.length() - 1;
    while (l > 0 && s[l] != '0') // find first position which is not equal to '1';
    {
        l--;
    }
    int zeroes = 0;
    vector<int> z;
    while (l > -1)
    {
        if (s[l] == '0')
        {
            zeroes++;
        }
        else
        {
            z.push_back(zeroes);
        }
        l--;
    }
    int len = z.size();
    if (len == 0)
    {
        return 0;
    }
    int min = z[len - 1];
    for (int i = len - 2; i > 0; i--)
    {
        if (z[i] + (len - 1 - i) < min)
        {
            min = z[i] + (len - 1 - i);
        }
    }
    if (z.size() < min)
    {
        return z.size();
    }
    return min;
}

int main()
{
    return 0;
}