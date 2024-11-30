//3340. Check Balanced String
/*
You are given a string num consisting of only digits. A string of digits is called balanced if the sum of the digits at even indices is equal to the sum of digits at odd indices.
Return true if num is balanced, otherwise return false.
*/
class Solution {
public:
    bool isBalanced(string num) {
        int esum{0},osum{0};
        for(int i = 0;i < num.size();i++)
        {
            std::string s{num[i]};
            int d = std::stoi(s);
            if(i % 2 == 0)
                esum += d;
            else
                osum += d;
        }

        return osum == esum;
    }
};
