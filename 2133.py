//2133. Check if Every Row and Column Contains All Numbers
/*
  An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.
  */
import numpy as np
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        a = np.array(matrix)
        res1 = True
        size = len(matrix[0])
        for i in range(size):
            j = len(list(set(matrix[i])))
            if j != size:
                res1 = False
                break
        res2 = True
        for i in range(size):
            j = len(set(a[:,i]))
            if j != size:
                res2 = False
                break
        return res1 and res2
