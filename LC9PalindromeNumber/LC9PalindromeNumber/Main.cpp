#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;
    }
    string s = "";
    while (x)
    {
        s.push_back((x % 10) + 48);
        x = x / 10;
    }
    int len = s.length(), i = 0;
    while (i < len / 2)
    {
        if (s[i] != s[(len - 1) - i])
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    cout << (1<<31) << endl;
    return 0;
}