//1380. Lucky Numbers in a Matrix
/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
  */
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        std::vector<int> lucky{};

        for(int i = 0;i < matrix.size();i++)
        {
            auto it = std::min_element(matrix[i].begin(),matrix[i].end());
            int minm = *it;
            int col = std::distance(matrix[i].begin(),it);
            int max = matrix[i][col];
            for(int j = 1;j < matrix.size();j++)
            {
                if(max < matrix[j][col])
                {
                    max = matrix[j][col];
                }

            }

            if(max == minm)
                lucky.push_back(max);
        }

        return lucky;    
    }
};
