#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
	bool rows[9][9] = { 0 };
	bool cols[9][9] = { 0 };
	bool nonants[9][9] = { 0 };
	int sector = 0, val = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sector = ((i / 3) * 3 + (j / 3));
			if (board[i][j] == '.')
			{
				continue;
			}
			else
			{
				val = board[i][j] - 49;
				if (rows[i][val])
				{
					return false;
				}
				rows[i][val] = 1;
				if (cols[j][val])
				{
					return false;
				}
				cols[j][val] = 1;
				if (nonants[sector][val])
				{
					return false;
				}
				nonants[sector][val] = 1;
			}
		}
	}
	return true;
}


int main()
{
	// vector<vector<char>> board = { {"5", "3", ".", ".", "7", ".", ".", ".", "."}, { "6",".",".","1","9","5",".",".","." }, { ".","9","8",".",".",".",".","6","." }, { "8",".",".",".","6",".",".",".","3" }, { "4",".",".","8",".","3",".",".","1" }, { "7",".",".",".","2",".",".",".","6" }, { ".","6",".",".",".",".","2","8","." }, { ".",".",".","4","1","9",".",".","5" }, { ".",".",".",".","8",".",".","7","9" } };
	// cout << isValidSudoku(board) << endl;
	return 0;
}