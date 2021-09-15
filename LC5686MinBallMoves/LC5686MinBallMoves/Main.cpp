#include<iostream>
#include <vector>
#include <string>

using namespace std;


int absVal(int x)
{
	if (x > 0)
	{
		return x;
	}
	else
	{
		return (x * (-1));
	}
}

/* Simple solution: O(n^2)
vector<int> minOperations(string boxes) 
{
	vector<int> answer;
	int len = boxes.length();
	for (int i = 0; i < len; i++)
	{
		answer.push_back(0);
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			answer[i] += abs((j - i)) * (boxes[j] - 48);
		}
	}
	return answer;
}*/ 

vector<int> minOperations(string boxes)
{
	vector<int> answer;
	int len = boxes.length();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		answer.push_back(0);
		answer[0] += i * (boxes[i] - 48);
		sum += boxes[i]-48;
	}
	int j = 1;
	int boxesL = (boxes[0]-48), boxesR = sum - boxesL;
	while (j < len)
	{
		answer[j] = (answer[j - 1] - boxesR) + boxesL;
		boxesL += (boxes[j]-48);
		boxesR -= (boxes[j]-48);
		j++;
	}
	return answer;
}

void printVector(vector<int>& nums)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << " ";
	}
}

int main()
{
	string boxes = "110101";
	vector<int> ans = minOperations(boxes);
	printVector(ans);
	return 0;
}