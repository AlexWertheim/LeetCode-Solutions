#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
}

int min(int x, int y)
{
	return (x < y) * x + (x >= y) * y;
}

int minZerosOnes(vector<int> bin)
{
	int len = bin.size(), zeroes = 0, ones = 0;
	for (int i = 0; i < len; i++)
	{
		if (bin[i] == 0)
		{
			zeroes++;
		}
		else
		{
			ones++;
		}
	}
	return min(zeroes, ones);
}

int minDominoRotations(vector<int>& A, vector<int>& B) 
{
	int len = A.size(), i = 0, j = 0;
	int alpha = A[0], beta = B[0];
	bool isA = 1, isB = 1;
	vector<int> flipsA, flipsB;
	flipsA.push_back(1), flipsB.push_back(1);
	while (i < len - 1 && isA)
	{
		if (A[i+1] == alpha)
		{
			flipsA.push_back(1);
			i++;
		}
		else if (B[i+1] == alpha)
		{
			flipsA.push_back(0);
			i++;
		}
		else
		{
			isA = 0;
		}
	}
	while (j < len - 1 && isB)
	{
		if (B[j+1] == beta)
		{
			flipsB.push_back(1);
			j++;
		}
		else if (A[j+1] == beta)
		{
			flipsB.push_back(0);
			j++;
		}
		else
		{
			isB = 0;
		}
	}
	// printVector(flipsB);
	if (isA && isB)
	{
		return min(minZerosOnes(flipsA), minZerosOnes(flipsB));
	}
	else if (isA)
	{
		return minZerosOnes(flipsA);
	}
	else if (isB)
	{
		return minZerosOnes(flipsB);
	}
	else
	{
		return -1;
	}
}

int main()
{
	cout << minDominoRotations(A, B) << endl;
	return 0;
}