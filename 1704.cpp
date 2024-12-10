//1704. Determine if String Halves Are Alike
/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false.
*/
class Solution {
public:
    bool halvesAreAlike(string s) {
        int left{0},right{0};
        std::set v{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = std::count_if(s.begin(),s.begin()+s.size()/2,[v](char c){return v.count(c) > 0;});
        int r = std::count_if(s.begin()+s.size()/2,s.end(),[v](char c){return v.count(c) > 0;});
        if(l == r)
            return true;
        
        return false;
        //for(int i = 0;i < s.length()/2;i++)
        //{
        //    if()
        //}
    }
};
