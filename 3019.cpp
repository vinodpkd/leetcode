//3019. Number of Changing Keys
/*
You are given a 0-indexed string s typed by a user. Changing a key is defined as using a key different from the last used key. For example, s = "ab" has a change of a key while s = "bBBb" does not have any.
Return the number of times the user had to change the key.
Note: Modifiers like shift or caps lock won't be counted in changing the key that is if a user typed the letter 'a' and then the letter 'A' then it will not be considered as a changing of key.
*/
class Solution {
public:
    int countKeyChanges(string s) {
        std::transform(s.begin(),s.end(),s.begin(),[](char c){return std::tolower(c);});
        //std::set<char> r(s.begin(),s.end());
        //return r.size()-1;
        int count{0};
        for(int i = 1;i < s.size();i++)
        {
            if(s[i] != s[i-1])
                count++;
        }

        return count;
    }
    
};
