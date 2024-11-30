//2828. Check if a String Is an Acronym of Words
/*
Given an array of strings words and a string s, determine if s is an acronym of words.
The string s is considered an acronym of words if it can be formed by concatenating the first character of each string in words in order. For example, "ab" can be formed from ["apple", "banana"], but it can't be formed from ["bear", "aardvark"].
Return true if s is an acronym of words, and false otherwise. 
*/

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {

        if(s.length() != words.size())
            return false;

    bool res = true;

    for(int i = 0;i < s.length();i++)
    {
        if(s[i] != words[i][0])
        {
            res = false;
            break;
        }
    }

    return res;
        
    }
};
