#include <iostream>
#include <vector>

using namespace std;

/* Cheesy implementation
bool isPowerOfThree(int n) 
{
    vector<int> powers = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
    for (int i = 0; i < 20; i++)
    {
        if (n == powers[i])
        {
            return true;
        }
    }
    return false;
} */

/* Recursive implementation
bool isPowerOfThree(int n) {
    if (n == 0)
    {
        return false;
    }
    if (n == 1)
    {
        return true;
    }
    if (n % 3 != 0)
    {
        return false;
    }
    else
    {
        return isPowerOfThree((n / 3));
    }
}*/

// Loop implementation
bool isPowerOfThree(int n) {
    while (n != 0)
    {
        if (n == 1)
        {
            return true;
        }
        if (n % 3 != 0)
        {
            return false;
        }
        else
        {
            n = (n / 3);
        }
    }
    return false;
}

int main()
{
    int n = 27;
    cout << isPowerOfThree(n) << endl;
	return 0;
}