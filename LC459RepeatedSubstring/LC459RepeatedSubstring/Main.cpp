#include<iostream>
#include<string>

using namespace std;

/* Slow way: check for patterns via length divisibility 
bool sameChars(string s)
    {
        for(int i = 0; i < s.length()-1; i++)
        {
            if(s[i] != s[i+1])
            {
                return false;
            }
        }
        return true;
    }

    bool isRepeat(string s, int r, int &len)
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 1; j < (len/r); j++)
            {
                if(s[i] != s[(i+j*r)])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len == 1)
        {
            return false;
        }
        vector<int> smallPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                                  43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        vector<int> divisors;
        int i = 0;
        while(i < 25)
        {
            if(len % smallPrimes[i] == 0 && len != smallPrimes[i])
            {
                divisors.push_back((len/smallPrimes[i]));
                divisors.push_back(smallPrimes[i]);
            }
            i++;
        }
        for(int j = 0; j < divisors.size(); j++)
        {
            if(isRepeat(s, divisors[j], len))
            {
                return true;
            }
        }
        if(sameChars(s))
        {
            return true;
        }
        return false;
    }
*/


// Extremely clever, but slow??

bool repeatedSubstringPattern(string s) {
    string ss = (s + s);
    ss.pop_back();
    return ss.find(s, 1) != -1;
}


int main()
{
	return 0;
}