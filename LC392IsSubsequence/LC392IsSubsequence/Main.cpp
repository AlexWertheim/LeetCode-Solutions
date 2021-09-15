#include <iostream>
#include <string>

using namespace std;


bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    int len = s.length();
    while (i < t.length())
    {
        if (t[i] == s[j])
        {
            j++;
        }
        i++;
    }
    if (j == len)
    {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}