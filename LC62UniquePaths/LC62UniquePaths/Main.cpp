#include <iostream>

using namespace std;

int choose(int n, int r) {
    double ans = 1.0;
    int k = min(r, n - r);
    for (int j = 1; j <= k; ++j) {
        ans = ans * n / j;
        n--;
    }
    return (int)ans;
}

// Math solution
int uniquePaths(int m, int n) {
    return choose((m - 1) + (n - 1), n - 1);
}

int main()
{
	return 0;
}