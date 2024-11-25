//1768. Merge Strings Alternately
/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int min = word1.size() > word2.size() ? word2.size() : word1.size();

        string res{""};

        for(int i = 0;i < min;i++)
        {
            res += word1[i];
            res += word2[i];
        }

        if(min < word2.size())
        {
            for(int i = min;i < word2.size();i++)
                res += word2[i];
        }

        if(min < word1.size())
        {
            for(int i = min;i < word1.size();i++)
                res += word1[i];
        }

        return res;

    }
};

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string merged;
        int i = 0, j = 0;

        while (i < word1.length() || j < word2.length()) {
            if (i < word1.length()) {
                merged += word1[i++];
            }
            if (j < word2.length()) {
                merged += word2[j++];
            }
        }
        return merged;
    }
};
