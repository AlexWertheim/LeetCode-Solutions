#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
	if (s.empty())
	{
		return 0;
	}
	int i = 0;
	int max = 0;
	int currlen = 0;
	string longest;
	size_t found;
	while (i < s.length())
	{
		found = longest.find(s.at(i)); // find the first position in the substring where the current character of s occurs
		longest.push_back(s.at(i)); // add s[i] to longest
		// cout << longest << ", " << i << endl;
		if (found == string::npos) // if there isn't any
		{
			i++; // increment the position in s
			currlen++; // increase the current length of our substring
			if (currlen > max) // check whether this exceeds our maximum
			{
				max = currlen; // update the max
			}
		}
		else // otherwise, we found an occurence; trim the substring from the front until the duplicate is removed
		{
			// cout << "Occurence of " << s.at(i) << " found at position " << found << endl;
			longest.erase(0, found+1);
			currlen -= found;
			i++;
		}
		// cout << longest << ", " << i << endl;
	}
	return max;
}

int main()
{
	string s = "pwwkew";
	cout << "Length of longest substring is: " << lengthOfLongestSubstring(s) << endl;
	return 0;
}