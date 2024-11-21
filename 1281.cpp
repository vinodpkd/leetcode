//1281. Subtract the Product and Sum of Digits of an Integer
/*
Given an integer number n, return the difference between the product of its digits and the sum of its digits. 
*/
class Solution {
public:
    int subtractProductAndSum(int n) {
        std::vector<int> digits{};
        while(n != 0)
        {
            int r = n % 10;
            digits.push_back(r);
            n = (n-r)/10;
        }

        int dsum = std::accumulate(digits.begin(),digits.end(),0);
        int prod = std::accumulate(digits.begin(),digits.end(),1,std::multiplies<int>());
        return prod - dsum;
    }
};
