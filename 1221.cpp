//1221. Split a String in Balanced Strings
/*
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
Given a balanced string s, split it into some number of substrings such that:
    Each substring is balanced.
Return the maximum number of balanced strings you can obtain.
  */
class Solution {
public:
    int balancedStringSplit(string s) {

        int count{0};

        std::map<char,int> map1{};

        int i = 1;
        map1[s[0]] = 1;

        while(i < s.size())
        {
            map1[s[i]]++;
            if(map1['L'] == map1['R'])
            {
                count++;
                map1['L'] = 0;
                map1['R'] = 0;
            }
            i++;
        }

        return count;
        
    }
};
