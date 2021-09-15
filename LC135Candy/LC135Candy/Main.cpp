#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) 
{
	int len = ratings.size();
	vector<int> candies;
	int minPos = 0, min = ratings[0];
	for (int i = 0; i < len; i++)
	{
		if (min < ratings[i])
		{
			minPos = i;
			min = ratings[i];
		}
		candies.push_back(0);
	}
	int i = minPos-1, j = minPos+1;
	candies[minPos] = 1;
	while (i > 0 && j < len)
	{
		if (ratings[i] > ratings[i + 1])
		{
			candies[i] = candies[i + 1] + 1;
			i--;
		}
		else
		{
			candies[i] = max(candies)
		}
	}
}

int main()
{
	return 0;
}