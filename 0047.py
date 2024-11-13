from itertools import permutations
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        a = permutations(nums)
        b = list(a)
        c = list(set(b))
        #d = list(c)
        return c
        
