#include <iostream>
#include <string>

using namespace std;

string mergeAlternately(string word1, string word2) {
	string merged;
	int sizeA = word1.length(), sizeB = word2.length();
	int min = (sizeA < sizeB) * sizeA + (sizeA >= sizeB) * sizeB;
	int max = (sizeA >= sizeB) * sizeA + (sizeA < sizeB) * sizeB;
	int diff = max - min;
	for (int i = 0; i < min; i++)
	{
		merged.push_back(word1[i]);
		merged.push_back(word2[i]);
	}
	if (diff > 0)
	{
		if (sizeA == max)
		{
			for (int j = 0; j < diff; j++)
			{
				merged.push_back(word1[(min+j)]);
			}
		}
		else
		{
			for (int j = 0; j < diff; j++)
			{
				merged.push_back(word2[(min + j)]);
			}
		}
	}
	return merged;
}

int main()
{
	string word1 = "abcd", word2 = "pqrs";
	cout << mergeAlternately(word1, word2) << endl;
	return 0;
}