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
algo.monster
    // Create three 9x9 matrices for rows, columns, and sub-boxes respectively.
        std::vector<std::vector<bool>> rowCheck(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> colCheck(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> subBoxCheck(9, std::vector<bool>(9, false));

        // Traverse the entire board to check each element.
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                // Read the current character.
                char currentChar = board[row][col];
              
                // Skip if the cell is empty (denoted by '.').
                if (currentChar == '.') continue;

                // Convert char digit to integer index (0 to 8).
                int num = currentChar - '0' - 1;

                // Calculate sub-box index based on row and column.
                int subBoxIndex = (row / 3) * 3 + (col / 3);

                // Check if the number has already been used in the current row, column, or sub-box.
                // If it has, then the Sudoku board is invalid.
                if (rowCheck[row][num] || colCheck[col][num] || subBoxCheck[subBoxIndex][num]) {
                    return false;
                }

                // Mark the number as used in the current row, column, and sub-box.
                rowCheck[row][num] = true;
                colCheck[col][num] = true;
                subBoxCheck[subBoxIndex][num] = true;
            }
        }

        // If all checks pass, then the board is valid.
        return true;
