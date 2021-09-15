#include <iostream>
#include <vector>

using namespace std;

void setColZeroes(vector<vector<int>>& matrix, int col, int numRows)
{
    for (int i = 0; i < numRows; i++)
    {
        matrix[i][col] = 0;
    }
}

void setRowZeroes(vector<vector<int>>& matrix, int row, int numCols)
{
    for (int i = 0; i < numCols; i++)
    {
        matrix[row][i] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    bool lastColZero = 0;
    bool lastRowZero = 0;
    for (int i = 0; i < numCols; i++)
    {
        if (matrix[numRows - 1][i] == 0)
        {
            lastRowZero = 1;
        }
    }
    for (int j = 0; j < numRows; j++)
    {
        if (matrix[j][numCols - 1] == 0)
        {
            lastColZero = 1;
        }
    }
    for (int i = 0; i < numRows - 1; i++)
    {
        for (int j = 0; j < numCols - 1; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[numRows - 1][j] = 0;
                matrix[i][numCols - 1] = 0;
            }
        }
    }
    for (int i = 0; i < numCols - 1; i++)
    {
        if (matrix[numRows - 1][i] == 0)
        {
            setColZeroes(matrix, i, numRows);
        }
    }
    for (int j = 0; j < numRows - 1; j++)
    {
        if (matrix[j][numCols - 1] == 0)
        {
            setRowZeroes(matrix, j, numCols);
        }
    }
    if (lastRowZero)
    {
        setRowZeroes(matrix, numRows - 1, numCols);
    }
    if (lastColZero)
    {
        setColZeroes(matrix, numCols - 1, numRows);
    }
}

int main()
{
	return 0;
}