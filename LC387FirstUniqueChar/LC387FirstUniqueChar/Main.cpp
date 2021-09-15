#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) 
{
	unordered_map<char, int> chars;
	for (int i = 0; i < s.length(); i++)
	{
		chars[s[i]]++;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (chars[s[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}

/* Cheesy solution
int firstUniqChar(string s)
{
	int chars[26] = {0};
	for (auto c : s)
	{
		chars[c - 'a']++;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (chars[s[i]-'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}

*/

int main()
{
	return 0;
}