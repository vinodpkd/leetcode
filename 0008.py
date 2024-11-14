import re
class Solution:
    def myAtoi(self, s: str) -> int:
        """
    Converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
    """

        match = re.match(r"^[\s]*([+-]?\d+)", s)  # Matches optional leading whitespace, an optional sign, and one or more digits.

        if not match:
            return 0

        result_str = match.group(1)

        try:
            result = int(result_str)
        except ValueError:
            return 0

        if result < -2**31:
            return -2**31
        elif result > 2**31 - 1:
            return 2**31 - 1
        else:
            return result
