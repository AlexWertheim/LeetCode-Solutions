#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool isSubsequence(string big, string small, vector<int> bigChars)
{
    int i = 0, j = 0;
    int smallLen = small.length(), bigLen = big.length();
    while (i < bigLen && j < smallLen)
    {
        // cout << i << ", " << j << endl;
        if (bigChars[small[j] - 'a'] == 0)
        {
            return false;
        }
        if (big[i] != small[j])
        {
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return (j == smallLen);
}

int numMatchingSubseq(string s, vector<string>& words) {
    int subseqs = 0;
    vector<int> sChars(26, 0);
    bool isSub = 0;
    for (int j = 0; j < s.length(); j++)
    {
        sChars[s[j] - 'a']++;
    }
    unordered_map<string, bool> seen;
    for (int i = 0; i < words.size(); i++)
    {
        // cout << words[i] << endl;
        if (seen.count(words[i]))
        {
            subseqs += seen[words[i]];
            continue;
        }
        else
        {
            isSub = isSubsequence(s, words[i], sChars);
            seen[words[i]] = isSub;
            subseqs += isSub;
        }
    }
    return subseqs;
}

int main()
{
    return 0;
}