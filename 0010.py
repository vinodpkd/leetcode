//10. Regular Expression Matching
/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/
import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        patt = re.compile(p)
        m = patt.match(s)
        if m and m.group() == s:

            return True
        return False

        
