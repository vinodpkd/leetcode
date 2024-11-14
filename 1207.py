#1207. Unique Number of Occurrences
from collections import defaultdict
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        d = defaultdict(int)
        for a in arr:
            d[a] += 1
        if len(d.values()) == len(list(set(d.values()))):
            return True
        return False
        
        
