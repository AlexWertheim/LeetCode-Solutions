#include<iostream>
#include<vector>

using namespace std;

int topLeft(vector<vector<int>>& board, int row, int column, bool T, bool L)
{
    if (T || L)
    {
        return 0;
    }
    else
    {
        return (board[row - 1][column - 1] > 0);
    }
}

int Left(vector<vector<int>>& board, int row, int column, bool L)
{
    if (L)
    {
        return 0;
    }
    else
    {
        return (board[row][column - 1] > 0);
    }
}

int bottomLeft(vector<vector<int>>& board, int row, int column, bool B, bool L)
{
    if (B || L)
    {
        return 0;
    }
    else
    {
        return (board[row + 1][column - 1] > 0);
    }
}

int Top(vector<vector<int>>& board, int row, int column, bool T)
{
    if (T)
    {
        return 0;
    }
    else
    {
        return (board[row - 1][column] > 0);
    }
}

int topRight(vector<vector<int>>& board, int row, int column, bool T, bool R)
{
    if (T || R)
    {
        return 0;
    }
    else
    {
        return (board[row - 1][column + 1] > 0);
    }
}

int Bottom(vector<vector<int>>& board, int row, int column, bool B)
{
    if (B)
    {
        return 0;
    }
    else
    {
        return (board[row + 1][column] > 0);
    }
}

int Right(vector<vector<int>>& board, int row, int column, bool R)
{
    if (R)
    {
        return 0;
    }
    else
    {
        return (board[row][column + 1] > 0);
    }
}

int bottomRight(vector<vector<int>>& board, int row, int column, bool B, bool R)
{
    if (B || R)
    {
        return 0;
    }
    else
    {
        return (board[row + 1][column + 1] > 0);
    }
}


int neighbors(vector<vector<int>>& board, int row, int column)
{
    int live = -1;
    if (board[row][column])
    {
        live = 1;
    }
    bool T = (row == 0);
    bool B = (row == board.size() - 1);
    bool L = (column == 0);
    bool R = (column == board[0].size() - 1);
    int nbrs = topLeft(board, row, column, T, L) +
        Left(board, row, column, L) +
        bottomLeft(board, row, column, B, L) +
        Top(board, row, column, T) +
        topRight(board, row, column, T, R) +
        Right(board, row, column, R) +
        bottomRight(board, row, column, B, R) +
        Bottom(board, row, column, B) +
        board[row][column]; // must remember whether > 0! tells you whether a 1 was there!
    return (live * nbrs);
}

void gameOfLife(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            board[i][j] = neighbors(board, i, j);
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] > 0)
            {
                if (board[i][j] == 3 || board[i][j] == 4)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
            else
            {
                if (board[i][j] == -3)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    return 0;
}
