#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t) 
{
	int len = s.length();
	unordered_map<char, char> isomorphism;
	unordered_map<char, bool> lettersMapped;
	int i = 0;
	while (i < len)
	{
		if (!isomorphism.count(s[i]))
		{
			if (lettersMapped.count(t[i]))
			{
				return 0;
			}
			else
			{
				isomorphism[s[i]] = t[i];
				lettersMapped[t[i]] = 1;
				i++;
			}
		}
		else
		{
			if (isomorphism[s[i]] == t[i] )
			{
				i++;
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	string s = "badc", t = "baba";
	if (isIsomorphic(s, t))
	{
		cout << "Isomorphic!" << endl;
	}
	else
	{
		cout << "Not isomorphic!" << endl;
	}
	return 0;
}