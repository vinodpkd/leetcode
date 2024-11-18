#342. Power of Four
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if 1 == n:
            return True

        if 0 == n:
            return False
        
        if n < 0:
            return False
        
        while (n != 0 and n != 1):
            r = n % 4
            #print("r = ",r)
            if 0 != r:
                    return False
            
            #print("n = ",n)
            n = n // 4
            #print("#n = ",n)

        return True
        
        
