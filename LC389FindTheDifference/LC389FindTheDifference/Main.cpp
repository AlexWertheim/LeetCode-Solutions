#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> letterCounts(string s, string t)
{
    vector<int> counts(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
    }
    counts[t[t.length() - 1] - 'a']--;
    return counts;
}

char findTheDifference(string s, string t) {
    vector<int> counts = letterCounts(s, t);
    for (int i = 0; i < 26; i++)
    {
        if (counts[i])
        {
            return i + 'a';
        }
    }
    return 'z';
}

int main()
{
    return 0;
}