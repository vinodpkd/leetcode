//2108. Find First Palindromic String in the Array
/*
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.
*/
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0;i < words.size();i++)
        {
            std::string s{words[i]};
            std::reverse(s.begin(),s.end());
            if(words[i] == s)
                return words[i];
        }

        return "";
    }
};
