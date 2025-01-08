//74. Search a 2D Matrix
/*
You are given an m x n integer matrix matrix with the following two properties:
    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.
*/
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int low = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        if(1 == m && 1 == n)
        {
            if(matrix[0][0] == target)
                return true;
            return false;
        }
        int high = m*n;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int i = mid/n;
            int j = mid % n;
            if(matrix[i][j] == target)
                return true;
            else
            {
                if(matrix[i][j] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return false;
    }
