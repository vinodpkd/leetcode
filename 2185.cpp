//2185. Counting Words With a Given Prefix
/*
You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c{0};
        for(int i = 0;i < words.size();i++)
        {
            int p = words[i].find(pref);
            if(0 == p)
                c++;
        }
        return c;
    }
};
