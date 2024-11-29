//1572. Matrix Diagonal Sum
/*
Given a square matrix mat, return the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int sum{0};

        for(int i = 0;i < mat.size();i++)
        {
            sum += mat[i][i];
            int j = mat.size() - 1 - i;
            if(i != j)
                sum += mat[i][j];
        }

        return sum;
        
    }
};
