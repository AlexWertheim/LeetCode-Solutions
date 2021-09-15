#include<iostream>
#include<unordered_map>

using namespace std;

int dynamicFib(int n, unordered_map<int, int>& Fibs)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        if (Fibs.count(n))
        {
            return Fibs[n];
        }
        else
        {
            Fibs[n] = dynamicFib(n - 1, Fibs) + dynamicFib(n - 2, Fibs);
            return Fibs[n];
        }
    }
}

int fib(int n) {
    unordered_map<int, int> Fibs;
    return dynamicFib(n, Fibs);
}

int main()
{
    return 0;
}