#include <iostream>

using namespace std;

int titleToNumber(string columnTitle) {
    int column = 0, len = columnTitle.length();
    unsigned int power = 1;
    while (len)
    {
        column += (columnTitle[len - 1] - 64) * power;
        len--;
        power = power * 26;
        columnTitle.pop_back();
    }
    return column;
}

int main()
{
	return 0;
}