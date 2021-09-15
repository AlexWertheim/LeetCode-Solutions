#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    vector<unsigned int> stairs;
    int i = 2;
    stairs.push_back(1);
    stairs.push_back(2);
    while (i <= n)
    {
        stairs.push_back((stairs[i - 1] + stairs[i - 2]));
        i++;
    }
    return stairs[n - 1];
}

int main()
{
    cout << climbStairs(46) << endl;
	return 0;
}