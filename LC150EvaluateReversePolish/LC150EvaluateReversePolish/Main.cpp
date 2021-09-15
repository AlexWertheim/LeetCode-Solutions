#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int stringToNum(string& s)
{
    int res = 0, mult = 1;
    bool minus = 0;
    if (s[0] == '-')
    {
        for (int i = s.length() - 1; i > 0; i--)
        {
            res += mult * (s[i] - '0');
            mult *= 10;
        }
        res *= -1;
    }
    else
    {
        for (int i = s.length() - 1; i > -1; i--)
        {
            res += mult * (s[i] - '0');
            mult *= 10;
        }
    }
    return res;
}

int evalRPN(vector<string>& tokens) {
    int len = tokens.size();
    int topElt = 0; 
    stack<int> nums;
        for (int i = 0; i < len; i++)
        {
            if (tokens[i] == "+")
            {
                topElt = nums.top();
                nums.pop();
                nums.top() += topElt;
            }
            else if (tokens[i] == "-")
            {
                topElt = nums.top();
                nums.pop();
                nums.top() -= topElt;
            }
            else if (tokens[i] == "*")
            {
                topElt = nums.top();
                nums.pop();
                nums.top() *= topElt;
            }
            else if (tokens[i] == "/")
            {
                topElt = nums.top();
                nums.pop();
                nums.top() /= topElt;
            }
            else
            {
                nums.push(stringToNum(tokens[i]));
            }
        }
        return nums.top();
}

int main()
{
    string s = "13";
    cout << stringToNum(s) << endl;
    return 0;
}