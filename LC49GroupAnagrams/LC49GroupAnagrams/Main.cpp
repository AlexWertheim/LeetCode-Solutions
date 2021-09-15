#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void printVector(vector<int> nums)
{
	for (auto x : nums)
	{
		cout << x << " ";
	}
}
/*
vector<int> letterCounts(string &s)
{
	vector<int> letters(26, 0);
	for (int i = 0; i < s.length(); i++)
	{
		letters[s[i] - 97]++;
	}
	return letters;
}*/

string sort(string& s)
{
	vector<int> letters(26, 0);
	for (int i = 0; i < s.length(); i++)
	{
		letters[s[i] - 97]++;
	}
	string sorted;
	for (int i = 0; i < 26; i++)
	{
		while (letters[i] > 0)
		{
			sorted.push_back(i + 97);
			letters[i]--;
		}
	}
	return sorted;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	vector<vector<string>> anagrams;
	unordered_map<string, vector<string>> grouped;
	for (auto x : strs)
	{
		grouped[sort(x)].push_back(x);
	}
	for (auto x : grouped)
	{
		anagrams.push_back(x.second);
	}
	return anagrams;
}


int main()
{
	string s = "abcba";
	string sorted = sort(s);
	cout << sorted << endl;
	// printVector(counts);
	// unordered_map<string, vector<string>> bloobis;
	// bloobis[counts] = "clombis";
	// cout << bloobis[counts] << endl;
	/* for (auto& x : bloobis)
	{
		cout << x.second << endl;
	}*/
	return 0;
}