#231. Power of Two

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if 1 == n:
            return True

        if 0 == n:
            return False
        
        if n < 0:
            return False
        
        while (n != 0 and n != 1):
            r = n % 2
            #print("r = ",r)
            if 0 != r:
                    return False
            
            #print("n = ",n)
            n = n // 2
            #print("#n = ",n)

        return True
