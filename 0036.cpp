//36. Valid Sudoku
/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < board.size();i++)
        {
            std::set<int> row{};
            for(int j = 0;j < board[0].size();j++)
            {
                if(board[i][j] != '.')
                {
                    if(row.find(board[i][j]) == row.end())
                    {
                        row.insert(board[i][j]);
                    }
                    else
                        return false;
                }
            }
        }
        
        for(int j = 0;j < board[0].size();j++)
        {
            std::set<int> row{};
            for(int i = 0;i < board.size();i++)
            {
                if(board[i][j] != '.')
                {
                    if(row.find(board[i][j]) == row.end())
                    {
                        row.insert(board[i][j]);
                    }
                    else
                        return false;
                }
            }
        }
        
        for(int i = 0;i < board.size();i = i+3)
        {
            
            for(int j = 0;j < board[0].size();j = j + 3)
            {
                std::set<int> row{};
                
                for(int k = 0;k < 3;k++)
                {
                    for(int p = 0;p < 3;p++)
                    {
                        if(board[i+k][j+p] != '.')
                        {
                            if(row.find(board[i+k][j+p]) == row.end())
                            {
                                row.insert(board[i+k][j+p]);
                            }
                            else
                                return false;
                        }
                    }
                }
                
            }
        }

        return true;
    }
};
-----------------
