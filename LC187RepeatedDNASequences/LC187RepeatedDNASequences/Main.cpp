#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    if (s.length() < 10)
    {
        return {};
    }
    string ten = "";
    unordered_map<string, int> repeats;
    vector<string> reps;
    for (int i = 0; i < s.length() - 9; i++)
    {
        ten = s.substr(i, 10);
        repeats[ten]++;
    }
    for (auto x : repeats)
    {
        if (x.second > 1)
        {
            reps.push_back(x.first);
        }
    }
    return reps;
}

int main()
{
	return 0;
}