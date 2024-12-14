//2373. Largest Local Values in a Matrix,Incomplete
/*
You are given an n x n integer matrix grid.
Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
    maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
Return the generated matrix.
*/
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> maxLocal{};
        std::vector<int> row{};
        int maxm = INT_MIN;
        for(int i = 0;i < grid.size()-2;i++)
        {
            
            for(int j = 0;j < 3;j++)
            {
                int tempmax = *std::max_element(grid[i+j].begin(),grid[i+j].begin()+3);
                maxm = std::max(maxm,tempmax);
            }

        }
        row.push_back(maxm);
        std::cout << maxm << '\n';

        return maxLocal;
    }
};
