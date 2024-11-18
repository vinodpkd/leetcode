#171. Excel Sheet Column Number

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        num = 0
        for i,x in enumerate(columnTitle[::-1]):
            j = (letters.index(x) + 1)*(26**i)
            num += j
        return num

        
