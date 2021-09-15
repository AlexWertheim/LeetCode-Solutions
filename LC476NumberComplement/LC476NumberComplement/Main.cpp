#include <iostream>

using namespace std;

int bitMask(int num)
{
    int res = 0;
    unsigned int mult = 1;
    while (num)
    {
        res += mult;
        num /= 2;
        mult *= 2;
    }
    return res;
}

int findComplement(int num) {
    return num ^ bitMask(num);
}

int main()
{
    return 0;
}