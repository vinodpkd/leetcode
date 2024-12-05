//258. Add Digits
/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/
class Solution {
public:
    int addDigits(int n) {
        if(10 > n)
            return n;

        while(n > 9)
        {
            int d{0};
            while(n != 0)
            {
                int r = n % 10;
                d += r;
                n = (n-r)/10;
            }
            n = d;
        }
        return n;
    }
};
