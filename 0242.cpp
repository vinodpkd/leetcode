//242. Valid Anagram
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise. 
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.length())
            return false;
        //std::multiset<char> u(s.begin(),s.end());
        //std::multiset<char> v(t.begin(),t.end());
        
        //if(u == v)
        //    return true;

        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());

        if(s == t)
            return true;

        return false;
    }
};
