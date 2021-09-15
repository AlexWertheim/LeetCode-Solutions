#include <iostream>

using namespace std;

int triangle(int n)
{
    if (n % 2 == 0)
    {
        return (n / 2) * (n + 1);
    }
    else
    {
        return ((n + 1) / 2) * n;
    }
}

int arrangeCoins(int n) {
    int high = 65535;
    int low = 1;
    int mid = 32768;
    if (n >= triangle(high))
    {
        return high;
    }
    while (high - low > 1)
    {
        if (n == triangle(mid))
        {
            return mid;
        }
        else if (n < triangle(mid))
        {
            high = mid;
            mid = (low + high) / 2;
        }
        else
        {
            low = mid;
            mid = (low + high) / 2;
        }
    }
    return mid;
}

int main()
{
    return 0;
}