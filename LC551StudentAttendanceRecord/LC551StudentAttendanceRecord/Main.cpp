#include<iostream>
#include<string>

using namespace std;

bool checkRecord(string s) {
    int aSum = 0;
    int lConsec = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'L')
        {
            lConsec++;
        }
        else if (s[i] == 'A')
        {
            lConsec = 0;
            aSum++;
        }
        else
        {
            lConsec = 0;
        }
        if (lConsec > 2 || aSum > 1)
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