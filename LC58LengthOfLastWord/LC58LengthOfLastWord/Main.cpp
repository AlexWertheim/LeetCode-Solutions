#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int len = s.length();
    bool firstLetter = 0;
    while (len > 0 && (!firstLetter))
    {
        if (s[(len - 1)] == ' ')
        {
            len--;
        }
        else
        {
            firstLetter = 1;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (s[(len - 1) - i] == ' ')
        {
            return i;
        }
    }
    cout << "len is: " << len << endl;
    return len;
}

int main()
{
    return 0;
}
