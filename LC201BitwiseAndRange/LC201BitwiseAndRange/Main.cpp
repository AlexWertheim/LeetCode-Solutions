#include <iostream>

using namespace std;

int logTwo(int n)
{
    int log = 0;
    while (n > 1)
    {
        n /= 2;
        log++;
    }
    return log;
}

int rangeBitwiseAnd(int left, int right) {
    // cout << logTwo(5) << endl;
    if (left == right)
    {
        return left;
    }
    int l = logTwo(left);
    if (l < logTwo(right))
    {
        return 0;
    }
    int firstD = logTwo(left ^ right);
    int mask = 0;
    for (int i = l; i >= firstD; i--)
    {
        mask += ((1 << i));
    }
    cout << mask << endl;
    return (left & mask);
}

int main()
{
    return 0;
}