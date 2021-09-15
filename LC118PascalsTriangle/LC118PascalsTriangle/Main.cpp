#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums)
{
	for(auto num : nums)
	{
		cout << num << " ";
	}
}

vector<int> pascalify(vector<int>& row)
{
	vector<int> nextRow = row;
	nextRow.push_back(1);
	int len = nextRow.size();
	for (int i = len - 2; i > 0; i--)
	{
		nextRow[i] += nextRow[i - 1];
	}
	return nextRow;
}

vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> pascalsTriangle;
	pascalsTriangle.push_back({ 1 });
	numRows--;
	int i = 0; 
	while (numRows > 0)
	{
		vector<int> row = pascalify(pascalsTriangle[i]);
		pascalsTriangle.push_back(row);
		i++;
		numRows--;
	}
	return pascalsTriangle;
}

int main()
{
	vector<int> row = { 1, 4, 6, 4, 1 };
	vector<int> nextRow = pascalify(row);
	printVector(nextRow);
	return 0;
}