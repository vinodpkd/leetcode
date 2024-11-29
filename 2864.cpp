//2864. Maximum Odd Binary Number
/*
You are given a binary string s that contains at least one '1'.
You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
Return a string representing the maximum odd binary number that can be created from the given combination.
Note that the resulting string can have leading zeros.
  */
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int len = s.length();
        std::multiset<char> mset(s.begin(),s.end());
        int count = mset.count('1');
        if(1 == count && s[len-1] == '1')
            return s;
        std::string t(count-1,'1');
        std::string z(len-count,'0');
        
        t = t + z + "1";

        return t;
        
        
    }
};
