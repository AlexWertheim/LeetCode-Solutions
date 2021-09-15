#include <iostream>

using namespace std;


int hammingWeight(uint32_t n) 
{
	int oneBits = 0;
	while (n > 0)
	{
		if ((n % 2) == 1)
		{
			oneBits++;
		}
		n = n >> 1;
	}
	return oneBits;
}

int main()
{
	cout << hammingWeight(11) << endl;
	return 0;
}