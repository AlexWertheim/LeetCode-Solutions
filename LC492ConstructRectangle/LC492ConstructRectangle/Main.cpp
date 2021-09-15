#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> constructRectangle(int area) {
    vector<int> dimensions(2, 0);
    for (int i = 1; i <= sqrt(area); i++)
    {
        if ((area % i) == 0)
        {
            dimensions[0] = (area / i);
            dimensions[1] = i;
        }
    }
    return dimensions;
}

int main()
{
    return 0;
}