//2894. Divisible and Non-divisible Sums Difference
/*
You are given positive integers n and m.
Define two integers as follows:
    num1: The sum of all integers in the range [1, n] (both inclusive) that are not divisible by m.
    num2: The sum of all integers in the range [1, n] (both inclusive) that are divisible by m.
Return the integer num1 - num2.
*/
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1{0},num2{0};
        int i = 1;
        while(i <= n)
        {
            if(i % m == 0)
                num2 += i;
            else
                num1 += i;

            i++;
        }

        return num1 - num2;
    }
};
