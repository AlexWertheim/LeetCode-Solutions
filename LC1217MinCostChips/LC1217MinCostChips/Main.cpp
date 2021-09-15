#include <iostream>
#include <vector>

using namespace std;

int minCostToMoveChips(vector<int>& position) 
{
	int len = position.size();
	int odd = 0;
	int even = 0;
	for (int i = 0; i < len; i++)
	{
		if ((position[i] % 2) == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	return ((odd < even) * odd + (odd >= even) * even);
}

int main()
{
	vector<int> position = { 2, 2, 2, 3, 3 };
	cout << minCostToMoveChips(position) << endl;
	return 0;
}