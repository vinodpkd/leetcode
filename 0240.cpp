//240. Search a 2D Matrix II
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Start from top-right corner
        int row = 0;
        int col = cols - 1;
        
        // Move left if target is smaller, down if target is larger
        while (row < rows && col >= 0) {
            int current = matrix[row][col];
            
            if (current == target) {
                return true;
            } else if (current > target) {
                // Target is smaller, move left
                col--;
            } else {
                // Target is larger, move down
                row++;
            }
        }
        
        return false;
    }
};
