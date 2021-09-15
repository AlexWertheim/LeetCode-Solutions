#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
	int len = gas.size();
	for (int i = 0; i < len; i++)
	{
		gas[i] -= cost[i];
	}
	int totalSum = 0, runningSum = 0;
	int index = 0, iter = 0;
	for (int i = 0; i < len; i++)
	{
		totalSum += gas[i];
	}
	if (totalSum < 0)
	{
		return -1;
	}
	else
	{
		while (iter < len)
		{
			runningSum += gas[iter];
			if (runningSum < 0)
			{
				iter++;
				index = iter;
				runningSum = 0;
			}
			else
			{
				iter++;
			}
		}
		return index;
	}
}

int main()
{
	vector<int> gas = {2, 3, 4}, cost = {3, 4, 3};
	cout << canCompleteCircuit(gas, cost) << endl;
	return 0;
}