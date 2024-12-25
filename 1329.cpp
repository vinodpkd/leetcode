//1329. Sort the Matrix Diagonally
/*
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int nr = mat.size();
        int nc = mat[0].size();
        for(int i = 0;i < nr-1;i++)
        {
            std::vector<int> u{};
            //std::pair<int,int> cord({i,0});
            u.push_back(mat[i][0]);
            int k = i;
            for(int j = 1;j < nc;j++)
            {
                if((i+j) < nr)
                    u.push_back(mat[i+j][j]);
                else
                    break;
            }
            std::sort(u.begin(),u.end());
            mat[i][0] = u[0];
            for(int j = 1;j < nc;j++)
            {
                if((i+j) < nr)
                    mat[i+j][j] = u[j];
                else
                    break;
            }
        }

        for(int j = 0;j < nc-1;j++)
        {
            std::vector<int> u{};
            
            u.push_back(mat[0][j]);
            
            for(int i = 1;i < nr;i++)
            {
                if((i+j) < nc)
                    u.push_back(mat[i][i+j]);
                else
                    break;
            }
            std::sort(u.begin(),u.end());
            mat[0][j] = u[0];
            for(int i = 1;i < nr;i++)
            {
                if((i+j) < nc)
                    mat[i][i+j] = u[i];
                else
                    break;
            }
        }


        return mat;
    }
};
