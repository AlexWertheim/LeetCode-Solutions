#include <iostream>
#include <vector>

using namespace std;

bool isSelfDiv(int n)
{
    int d = n;
    int dig = 0;
    while (d)
    {
        dig = d % 10;
        if (dig == 0 || (n % (dig)) != 0)
        {
            return false;
        }
        d /= 10;
    }
    return true;
}

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> divs;
    for (int i = left; i <= right; i++)
    {
        if (isSelfDiv(i))
        {
            divs.push_back(i);
        }
    }
    return divs;
}

int main()
{
    return 0;
}
