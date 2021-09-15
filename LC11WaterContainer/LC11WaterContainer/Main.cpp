#include <iostream>
#include <vector>

using namespace std;

int min(int num1, int num2)
{
    if (num1 < num2)
    {
        return num1;
    }
    return num2;
}

int maxArea(vector<int>& height)
{
    int i = 0;
    int j = height.size()-1;
    int maxA = 0;
    int area = 0;
    while (i < j)
    {
        area = min(height.at(i), height.at(j)) * (j - i);
        if (area > maxA)
        {
            maxA = area;
        }
        if (height.at(i) < height.at(j))
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return maxA;
}

int main()
{
    int container[] = {4, 3, 2, 1, 4};
    vector<int> heights(container, container + sizeof(container) / sizeof(int));
	std::cout << maxArea(heights) << std::endl;
	return 0;
}