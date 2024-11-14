# String to Integer (atoi),Not completed,better solve by regex
class Solution:
    def myAtoi(self, s: str) -> int:
        if s.strip() == '':
            return 0
        if '+' in s and '-' in s:
            return 0
            
        digitflag = 0
        for i in s:
            if i.isdigit():
                digitflag = 1
                break
        if 0 == digitflag:
            return 0

        sum1 = sum([1 for x in s if '-' == x])
        sum2 = sum([1 for x in s if '+' == x])

        if sum1 > 1 or sum2 > 1:
            return 0
        

        if "+" in s:
            s = s.replace('+','')

        if '+' in s and '-' in s:
            x1 = s.index('+')
            x2 = s.index('-')
            if x1 < x2:
                return 0
        digits = ''
        for x,i in enumerate(s.strip()):
            if 0 == x and not(i.isdigit()):
                if '-' == i:
                    pass
                else:
                    return 0
                
                
            if i.isdigit() or '-' == i or '+' == i:
                digits += i
            else:
                break
                #return 0
            
        print(digits)
        if '-' in digits and digits[0] != '-':
            return 0
        if '+' in digits:
            #digits = digits.replace('+','')
            return 0
        if '-' == digits:
            return 0

        if '+' in digits and not ('-' in digits):
            digits = digits.replace('+','')
            
        print(digits)
        n = int(digits)
        if n < -2**(31):
            return -2**(31)
        if n > (2**31 - 1):
            return 2**31 - 1
        return n
        

#print(myAtoi(' -42'))
print(myAtoi('words and 987'))
print(myAtoi('-+12'))
print(myAtoi('+12'))
