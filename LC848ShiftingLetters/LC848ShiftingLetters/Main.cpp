#include<iostream>
#include<vector>
#include<string>

using namespace std;

string shiftingLetters(string s, vector<int>& shifts) {
    int sum = 0;
    int letter = 0;
    for (int i = shifts.size() - 1; i > -1; i--)
    {
        sum = (sum + shifts[i]) % 26;
        letter = ((s[i] - 'a') + sum) % 26;
        s[i] = 'a' + letter;
    }
    return s;
}

int main()
{
    return 0;
}