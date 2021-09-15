#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min(int x, int y)
{
	return (x < y) * x + (x >= y) * y;
}

int firstDisagree(string a, string b)
{
	if (a.empty() || b.empty())
	{
		return 0;
	}
	int aLen = a.length(), bLen = b.length();
	int n = min(aLen, bLen);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			return i;
		}
	}
	return n;
}

string longestCommonPrefix(vector<string>& strs) 
{
	if (strs.size() == 0)
	{
		return "";
	}
	string prefix = strs[0];
	int len = strs.size(), i = 1, pos = 0;
	while (i < len && prefix != "")
	{
		pos = firstDisagree(prefix, strs[i]);
		prefix.resize(pos);
		i++;
	}
	return prefix;
}

int main()
{
	// string s = "flower", t = "flight";
	// cout << firstDisagree(s, t) << endl;
	vector<string> strs = { "flower", "car", "flight" };
	cout << longestCommonPrefix(strs) << endl;
	return 0;
}