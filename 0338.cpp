//338. Counting Bits
/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
*/
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> bits(n+1);
        for(int i = 0;i <=n;i++)
        {
            bits[i] = __builtin_popcount(i);
        }
        return bits;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> a{};
        for(int i = 0;i <= n;i++)
        {
            std::bitset<32> b(i);
            a.push_back(b.count());
        }
        return a;
    }
};
