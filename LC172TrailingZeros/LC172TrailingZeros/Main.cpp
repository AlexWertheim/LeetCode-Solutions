#include <iostream>

using namespace std;

int highestFive(int x)
{
	int counter = 0;
	while (x > 4)
	{
		x = x / 5;
		counter++;
	}
	return counter;
}

int trailingZeroes(int n) 
{
	int zeroes = 0, i = 0, fives = highestFive(n), power = 5;
	while (i < fives)
	{
		zeroes += (n / power);
		power *= 5;
		i++; 
	}
	return zeroes;
}

int main()
{
	cout << trailingZeroes(25) << endl;
	return 0;
}