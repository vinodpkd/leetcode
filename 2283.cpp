//2283. Check if Number Has Equal Digit Count and Digit Value
/*
You are given a 0-indexed string num of length n consisting of digits.
Return true if for every index i in the range 0 <= i < n, the digit i occurs num[i] times in num, otherwise return false. 
*/

class Solution {
public:
    bool digitCount(string num) {
        //bool check{true};
        for(int i = 0;i < num.length();i++)
        {
            std::string s = std::to_string(i);
            char ch = s[0];
            int count = std::count_if(num.begin(),num.end(),[ch](char c){return c == ch;});
            std::string r = std::to_string(count);
            if(r[0] != num[i])
                return false;
        }
        return true;
    }
};
