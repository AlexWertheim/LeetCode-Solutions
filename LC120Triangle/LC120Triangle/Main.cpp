#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int len = triangle.size();
    if (len == 1)
    {
        return triangle[0][0];
    }
    for (int i = len - 1; i > 0; i--)
    {
        for (int j = 0; j < (triangle[i].size() - 1); j++)
        {
            if (triangle[i][j] < triangle[i][j + 1])
            {
                triangle[i - 1][j] += triangle[i][j];
            }
            else
            {
                triangle[i - 1][j] += triangle[i][j + 1];
            }
        }
    }
    return triangle[0][0];
}

int main()
{
	return 0;
}