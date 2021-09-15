#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> ranChars(26, 0);
    vector<int> magChars(26, 0);
    for (int i = 0; i < ransomNote.length(); i++)
    {
        ranChars[ransomNote[i] - 'a']++;
    }
    for (int j = 0; j < magazine.length(); j++)
    {
        magChars[magazine[j] - 'a']++;
    }
    for (int k = 0; k < 26; k++)
    {
        if (ranChars[k] > magChars[k])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}