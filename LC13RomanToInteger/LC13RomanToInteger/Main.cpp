#include <iostream>
#include <string>

using namespace std;

int romanToInt(string s) 
{
	int i = s.length() - 1, val = 0;
	char latestChar = '-'; 
	while (i > -1)
	{
		if (s[i] == 'I')
		{
			if (latestChar == 'X' || latestChar == 'V')
			{
				val -= 1;
			}
			else
			{
				val += 1;
			}
		}
		else if (s[i] == 'V')
		{
			val += 5;
		}
		else if (s[i] == 'X')
		{
			if (latestChar == 'C' || latestChar == 'L')
			{
				val -= 10;
			}
			else
			{
				val += 10;
			}
		}
		else if (s[i] == 'L')
		{
			val += 50;
		}
		else if (s[i] == 'C')
		{
			if (latestChar == 'M' | latestChar == 'D')
			{
				val -= 100;
			}
			else
			{
				val += 100;
			}
		}
		else if (s[i] == 'D')
		{
			val += 500;
		}
		else // M
		{
			val += 1000;
		}
		latestChar = s[i];
		i--;
	}
	return val;
}


int main()
{
	cout << romanToInt("MCMXCIV");
	return 0;
}