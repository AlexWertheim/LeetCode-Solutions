#include <iostream>
#include <unordered_map>

using namespace std;

int sumOfSquaresDigits(int n)
{
	int sum = 0;
	int currDig = 0;
	while (n != 0)
	{
		currDig = (n % 10);
		sum += (currDig * currDig);
		n = (n / 10);
	}
	return sum;
}

bool isHappy(int n) 
{
	unordered_map<int, bool> loops;
	while (n != 1)
	{
		if (loops.count(n))
		{
			return 0;
		}
		else
		{
			loops[n] = 1;
			n = sumOfSquaresDigits(n);
		}
	}
	return 1;
}

/* Cheeky solution
bool isHappy(int n)
{
	int happyNums[113] = { 1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100, 103, 109, 129, 130, 133, 139, 167, 176, 188, 190, 192, 193, 203, 208, 219, 226, 230, 236, 239, 262, 263, 280, 291, 293, 301, 302, 310, 313, 319, 320, 326, 329, 331, 338, 356, 362, 365, 367, 368, 376, 379, 383, 386, 391, 392, 397, 404, 409, 440, 446, 464, 469, 478, 487, 490, 496, 536, 556, 563, 565, 566, 608, 617, 622, 623, 632, 635, 637, 638, 644, 649, 653, 655, 656, 665, 671, 673, 680, 683, 694, 700, 709, 716, 736, 739, 748, 761, 763, 784, 790, 793, 802, 806 };
	int s = sumOfSquaresDigits(n);
	for (int i = 0; i < 113; i++)
	{
		if (happyNums[i] == s)
		{
			return 1;
		}
	}
	return 0;
}*/

int main()
{
	/* int counter = 0;
	cout << "[";
	for (int i = 1; i < 811; i++)
	{
		if (isHappy(i))
		{
			counter++;
			cout << i << ",";
		}
	}
	cout << "]" << endl;
	cout << counter << endl; */
	return 0;
}