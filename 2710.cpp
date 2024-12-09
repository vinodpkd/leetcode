//2710. Remove Trailing Zeros From a String
/*
Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.
*/
class Solution {
public:
    string removeTrailingZeros(string num) {
        while(true)
        {
            if(num[num.size()-1] == '0')
                num.pop_back();//string erase from the end
            else
            {
                break;
            }
        }

        return num;
    }
};
