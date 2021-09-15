#include<iostream>
#include<string>
#include<vector>

using namespace std;

string intToStr(int n)
{
    if (n == 0)
    {
        return "0";
    }
    string res;
    int dig = 0;
    while (n)
    {
        dig = n % 10;
        res.push_back('0' + dig);
        n /= 10;
    }
    int i = 0, j = res.length() - 1;
    char temp;
    while (i < j)
    {
        temp = res[i];
        res[i] = res[j];
        res[j] = temp;
        i++;
        j--;
    }
    return res;
}

string getHint(string secret, string guess) {
    int bulls = 0, cows = 0;
    vector<int> sDigs(10, 0);
    vector<int> gDigs(10, 0);
    for (int i = 0; i < secret.length(); i++)
    {
        if (secret[i] == guess[i])
        {
            bulls++;
        }
        else
        {
            sDigs[secret[i] - '0']++;
            gDigs[guess[i] - '0']++;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        cows += min(sDigs[j], gDigs[j]);
    }
    return intToStr(bulls) + "A" + intToStr(cows) + "B";
}

int main()
{
    return 0;
}