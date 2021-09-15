#include<iostream>
#include<vector>

using namespace std;

void explore(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited, int& rows, int& cols)
{
    // cout << i << ", " << j << endl;
    visited[i][j] = 1;
    if (grid[i][j] == '1')
    {
        if (i < (rows - 1) && !visited[i + 1][j]) // down
        {
            explore(i + 1, j, grid, visited, rows, cols);
        }
        if (i > 0 && !visited[i - 1][j]) // up
        {
            explore(i - 1, j, grid, visited, rows, cols);
        }
        if (j < (cols - 1) && !visited[i][j + 1]) // right
        {
            explore(i, j + 1, grid, visited, rows, cols);
        }
        if (j > 0 && !visited[i][j - 1]) // left
        {
            explore(i, j - 1, grid, visited, rows, cols);
        }
    }

}

int numIslands(vector<vector<char>>& grid) {
    int islands = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!visited[i][j])
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    explore(i, j, grid, visited, rows, cols);
                }
                else
                {
                    visited[i][j] = 1;
                }
                // cout << i << ", " << j << endl;
            }
        }
    }
    return islands;
}

int main()
{
    return 0;
}