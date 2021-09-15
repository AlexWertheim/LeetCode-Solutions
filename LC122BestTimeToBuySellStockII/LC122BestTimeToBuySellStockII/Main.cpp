#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
	int maxProfits = 0;
	for (int i = 0; i < prices.size()-1; i++)
	{
		if (prices[i] < prices[i + 1])
		{
			maxProfits += (prices[i + 1] - prices[i]);
		}
	}
	return maxProfits;
}

int main()
{
	vector<int> prices = { 1,2,3,4,5 };
	cout << maxProfit(prices) << endl;
	return 0;
}