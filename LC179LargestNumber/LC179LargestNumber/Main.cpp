#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool static lexicoLess(string s, string t)
{
    if (s == t)
    {
        return false;
    }
    int sLen = s.length(), tLen = t.length();
    int i = 0;
    while (i <= sLen * tLen)
    {
        if (s[i % sLen] > t[i % tLen])
        {
            return false;
        }
        if (s[i % sLen] < t[i % tLen])
        {
            return true;
        }
        i++;
    }
    return false;
}

string intToStr(int n)
{
    if (n == 0)
    {
        return "0";
    }
    string s;
    while (n)
    {
        s.push_back((n % 10) + '0');
        n /= 10;
    }
    char temp;
    int len = s.length() - 1;
    int i = 0;
    while (i < len)
    {
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
        i++;
        len--;
    }
    return s;
}

string largestNumber(vector<int>& nums) {
    vector<string> sortedNums;
    string s;
    for (int i = 0; i < nums.size(); i++)
    {
        sortedNums.push_back(intToStr(nums[i]));
    }
    std::sort(sortedNums.begin(), sortedNums.end(), lexicoLess);
    if (sortedNums.back() == "0")
    {
        return "0";
    }
    for (int i = sortedNums.size() - 1; i > -1; i--)
    {
        s.append(sortedNums[i]);
    }
    return s;
}

int main()
{
    return 0;
}