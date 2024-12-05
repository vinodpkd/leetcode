//2427. Number of Common Factors
/*
Given two positive integers a and b, return the number of common factors of a and b.
An integer x is a common factor of a and b if x divides both a and b.
*/

class Solution {
public:
    int commonFactors(int a, int b) {
        int g = std::gcd(a,b);
        if (1 == g)
            return 1;
        int count{2};
        for(int i = 2;i < g;i++)
        {
            if(a % i == 0 && b%i == 0)
                count++;
        }
        return count;
    }
};
