#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
	int profit = 0, maxProfit = 0, lowPrice = prices[0], highPrice = prices[0];
	for (int i = 0; i < prices.size()-1; i++)
	{
		if (prices[i + 1] < lowPrice) // nadir; start looking for maxes again. Cash in!
		{
			profit = highPrice - lowPrice;
			if (profit > maxProfit)
			{
				maxProfit = profit;
			}
			lowPrice = prices[i+1];
			highPrice = prices[i + 1];
			profit = 0;
		}
		else
		{
			if (prices[i + 1] > highPrice)
			{
				highPrice = prices[i + 1];
				cout << lowPrice << ", " << highPrice << endl;
			}
		}
	}
	profit = highPrice - lowPrice;
	if (profit > maxProfit)
	{
		maxProfit = profit;
	}
	return maxProfit;
}

int main()
{
	vector<int> prices = { 1, 5 };
	cout << maxProfit(prices) << endl;
	return 0;
}