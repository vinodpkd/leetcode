//1323. Maximum 69 Number
/*
You are given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
*/
class Solution {
public:
    int maximum69Number (int num) {
        std::string s = std::to_string(num);
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == '6')
            {
                s[i] = '9';
                break;
            }
                
        }

        return std::stoi(s);
    }
};
