#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t) 
{
	int sChars[26] = { 0 };
	int tChars[26] = { 0 };
	int sLen = s.length(), tLen = t.length();
	if (sLen != tLen)
	{
		return false;
	}
	for (int i = 0; i < sLen; i++)
	{
		sChars[s[i] - 'a']++;
		tChars[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (sChars[i] != tChars[i])
		{
			return false;
		}
	}
	return true;
}



int main()
{
	cout << isAnagram("rat", "car") << endl;
	return 0;
}