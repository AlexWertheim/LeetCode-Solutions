#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToStr(int n)
{
    string s = "";
    while (n)
    {
        s.push_back((n % 10) + 48);
        n = n / 10;
    }
    int len = s.length();
    char temp = 'a';
    for (int i = 0; i < len / 2; i++)
    {
        temp = s[i];
        s[i] = s[(len - 1) - i];
        s[(len - 1) - i] = temp;
    }
    return s;
}
vector<string> fizzBuzz(int n) {
    vector<string> fizzes;
    string c = "";
    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
        {
            fizzes.push_back("FizzBuzz");
        }
        else if (i % 5 == 0)
        {
            fizzes.push_back("Buzz");
        }
        else if (i % 3 == 0)
        {
            fizzes.push_back("Fizz");
        }
        else
        {
            c = intToStr(i);
            fizzes.push_back(c);
        }
    }
    return fizzes;
}

int main()
{
    return 0;
}