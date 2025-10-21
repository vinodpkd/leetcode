//191. Number of 1 Bits
/*
Given a positive integer n, write a function that returns the number of
set bits
in its binary representation (also known as the Hamming weight).
*/
class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        std::bitset<32> b(n);
        return b.count();
    }
};
