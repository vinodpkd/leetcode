//1351. Count Negative Numbers in a Sorted Matrix
/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
*/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c{0};
        for(int i = 0;i < grid.size();i++)
        {
            for(auto j = grid[i].rbegin();j != grid[i].rend();j++)
            {
                if(*j < 0)
                {
                    c++;
                }
                else
                {
                    break;
                }
            }
        }
        return c;
    }
};
