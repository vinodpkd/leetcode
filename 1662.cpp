//1662. Check If Two String Arrays are Equivalent
/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1{""};
        for(int i = 0;i < word1.size();i++)
        {
            s1 += word1[i];
        }

        string s2{""};
        for(int i = 0;i < word2.size();i++)
        {
            s2 += word2[i];
        }

        if(s1 == s2)
            return true;
            
        return false;
    }
};
