#60. Permutation Sequence
from itertools import permutations
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        a = list(permutations(range(1,n+1)))[k-1]
        a = "".join([str(x) for x in a])
        return a
        
