#14. Longest Common Prefix
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        minm = min([len(x) for x in strs])
        if 0 == minm:
            return ''
        i = 0
        s = ""
        while i < minm:
            a = len(list(set([x[i] for x in strs])))
            if 1 == a:
                s += strs[0][i]
                i = i + 1
            else:
                break
        return s

        
        
