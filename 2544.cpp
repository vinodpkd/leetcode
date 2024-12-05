//2544. Alternating Digit Sum
/*
You are given a positive integer n. Each digit of n has a sign according to the following rules:

    The most significant digit is assigned a positive sign.
    Each other digit has an opposite sign to its adjacent digits.

Return the sum of all digits with their corresponding sign.
*/
class Solution {
public:
    int alternateDigitSum(int n) {
        if(10 > n)
            return n;
        std::string s{std::to_string(n)};
        int asum{0};
        int m{1};
        for(auto i = s.begin();i != s.end();i++)
        {
            std::string t{*i};
            int d = std::stoi(t);
            asum += m*d;
            m = -m;
        }
        
        return asum;
    }
};
