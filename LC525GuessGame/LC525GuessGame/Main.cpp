#include <iostream>

using namespace std;


int guessNumber(int n) {
	unsigned int high = n, low = 1, key = (high + low) / 2;
	while (guess(key) != 0)
	{
		if (guess(key) == -1)
		{
			high = key;
			key = (high + low) / 2;
		}
		else
		{
			low = key;
			key = ((high + low) / 2) + 1;
		}
	}
	return key;
}