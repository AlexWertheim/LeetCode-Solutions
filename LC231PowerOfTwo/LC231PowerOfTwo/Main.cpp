#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) 
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		if (n % 2 == 0)
		{
			return isPowerOfTwo((n / 2));
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	if (isPowerOfTwo(16))
	{
		cout << "Success!" << endl;
	}
	else
	{
		cout << "Failure!" << endl;
	}
	return 0;
}