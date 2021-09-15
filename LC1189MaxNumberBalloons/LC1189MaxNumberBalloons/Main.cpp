#include<iostream>
#include <vector>
#include<string>

using namespace std;

int maxNumberOfBalloons(string text) {
    vector<int> chars(26, 0);
    for (int i = 0; i < text.length(); i++)
    {
        chars[text[i] - 'a']++;
    }
    chars[11] /= 2;
    chars[14] /= 2;
    int min = 1450;
    vector<int> validLetters = { 0, 1, 11, 13, 14 };
    for (int j = 0; j < 5; j++)
    {
        if (chars[validLetters[j]] < min)
        {
            min = chars[validLetters[j]];
        }
    }
    return min;
}

int main()
{
    return 0;
}