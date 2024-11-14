#Minimum Consecutive Cards to Pick 
from collections import defaultdict
class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        if (len(cards) == len(set(cards))):
            return -1
        #dct = defaultdict(int)
        dct_occur = defaultdict(list)
        minm = len(cards)
        for i,x in enumerate(cards):
            #dct[x] = dct[x] + 1
            dct_occur[x].append(i)
            if len(dct_occur[x]) > 1:
                dist = dct_occur[x][-1] - dct_occur[x][-2] + 1
                minm = min([dist,minm])
        return minm
            
