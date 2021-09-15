#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>>& matrix)
{
	int dim = matrix[0].size();
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void transpose(vector<vector<int>>& matrix)
{
	int dim = matrix[0].size();
	int temp;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < i; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

void reflect(vector<vector<int>>& matrix)
{
	int dim = matrix[0].size();
	int halfDim;
	if (dim % 2 == 1)
	{
		halfDim = (dim / 2) + 1;
	}
	else
	{
		halfDim = dim / 2;
	}
	int temp;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < halfDim; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[i][(dim - 1) - j];
			matrix[i][(dim - 1) - j] = temp;
		}
	}
}


void rotate(vector<vector<int>>& matrix) 
{
	/* int dim = matrix[0].size();
	int temp;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][(dim-1)  - i];
			matrix[j][(dim-1) - i] = temp;
		}
	} */
	transpose(matrix);
	reflect(matrix);
}

int main()
{
	// vector<vector<int>> matrix = { {5, 1, 9, 11},{2, 4, 8, 10},{13, 3, 6, 7}, {15, 14, 12, 16} };
	vector<vector<int>> matrix = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	printMatrix(matrix);
	rotate(matrix);
	printMatrix(matrix);
	return 0;
}