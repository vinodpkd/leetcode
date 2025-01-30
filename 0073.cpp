//73. Set Matrix Zeroes
/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::set<int> cols{};
        for(int i = 0;i < matrix.size();i++)
        {
            auto it = matrix[i].begin();
            bool flag{false};
            while((it = std::find_if(it,matrix[i].end(),[](int x){return x == 0; })) != matrix[i].end())
            {
                cols.insert(std::distance(matrix[i].begin(),it));
                flag = true;
                it++;
            }

            if(true == flag)
            {
                std::fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }

        for(auto& c : cols)
        {
            for(int j = 0;j < matrix.size();j++)
            {
                matrix[j][c] = 0;
            }
        }
    }
}
};
