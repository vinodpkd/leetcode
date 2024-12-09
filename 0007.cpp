//7. Reverse Integer
/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/
class Solution {
public:
    int reverse(int x) {
        if(-2147483648 == x)
            return 0;
        long long res = 0; // Use long long to avoid overflow during intermediate calculations
        bool negative = false;

        if (x < 0) {
            negative = true;
            x = -x; // Make x positive for easier processing
        }

        while (x > 0) {
            res = res * 10 + x % 10;
            x /= 10;

            // Check for overflow before assigning to the result
            if (res >= INT_MAX || res <= INT_MIN) {
                return 0; // Return 0 if overflow occurs
            }
        }

        return negative ? -res : res; // Return the result with the correct sign
    }
};
