#include<iostream>
#include<vector>
#include<string>

using namespace std;

// can make better memory-wise by just resetting separate count vector for each word
// don't think this actually does better speed-wise though

vector<string> commonChars(vector<string>& words) {
    vector<string> common;
    vector<vector<int>> chars(words.size(), vector<int>(26, 0));
    vector<int> min(26, 1000);
    string s = "a";
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            chars[i][words[i][j] - 'a']++;
        }
    }
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (chars[i][j] < min[j])
            {
                min[j] = chars[i][j];
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < min[i]; j++)
        {
            s[0] = 'a' + i;
            common.push_back(s);
        }
    }
    return common;
}

int main()
{
    return 0;
}