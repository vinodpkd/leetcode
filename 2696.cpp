//2696. Minimum String Length After Removing Substrings
/*
You are given a string s consisting only of uppercase English letters.
You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.
Return the minimum possible length of the resulting string that you can obtain.
Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
*/
class Solution {
public:
    int minLength(string s) {
        while(s.find("AB") != -1 || s.find("CD") != -1)
        {
            int ind = s.find("AB");
            if(ind != -1)
                s.erase(s.begin()+ind,s.begin()+ind+2);
            ind = s.find("CD");
            if(ind != -1)
                s.erase(s.begin()+ind,s.begin()+ind+2);
        }
        return s.length();
    }
};
