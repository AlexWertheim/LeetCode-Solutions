#include <iostream>
#include <string>

using namespace std;

int min(int x, int y)
{
	return (x < y) * x + (x >= y) * y;
}

int minOperations(string s) 
{
	int min1 = 0, min2 = 0;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		min1 += ((s[i] + (i % 2)) % 2);
		min2 += ((s[i] + (i+1 % 2)) % 2);
	}
	return(min(min1, min2));
}

int main()
{
	string s = "011";
	cout << minOperations(s) << endl;
	return 0;
}