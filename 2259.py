#2259 remove-digit-from-number-to-maximize-result Beats 100% time
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        indices = [i for i, x in enumerate(number) if x == digit]
        numbers = []
        for ind in indices:
            temp = int(number[:ind] + number[ind+1:])
            numbers.append(temp)
        return str(max(numbers))
        
