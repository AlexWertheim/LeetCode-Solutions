#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) 
{
	uint32_t reversed = 0;
	int i = 0;
	while(n != 0)
	{
		reversed += (n & 1)*(1 << (31 - i));
		i++; 
		n = n >> 1; 
	}
	return reversed;
}

int main()
{
	cout << reverseBits(43261596) << endl;
	return 0;
}