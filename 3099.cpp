//3099. Harshad Number
/*
An integer divisible by the sum of its digits is said to be a Harshad number. You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.
*/
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        if (0 == x)
            return -1;
        int n = x;
        int sum{0};
        while(x != 0)
        {
            int r = x % 10;
            sum += r;
            x = (x-r)/10;
        }

        if(n % sum == 0)
            return sum;
        return -1;

        
    }

    
};
