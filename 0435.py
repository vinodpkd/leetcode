#435. Non-overlapping Intervals
from collections import defaultdict as df
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return false
        #dictOne = df(list)
        #dictTwo = df(list)
        #for i in range(len(s)):
        #    dictOne[s[i]].append(i)
        #    dictTwo[t[i]].append(i)
        keys = []
        values = []
        dict = {}
        for i in range(len(s)):
            if not s[i]  in dict.keys():
                print(i,",s ",s[i])
                keys.append(s[i])
                dict[s[i]] = t[i]
                print(i,",t ",t[i])
                print(dict.keys(),",",dict.values())
                if len(set(dict.keys())) != len(set(dict.values())):
                    return False
                values.append(t[i])
            else:
                if dict[s[i]] != t[i]:
                    return False
            
        return True


        
        
