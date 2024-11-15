//242. Valid Anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::multiset<char> msetOne(s.begin(),s.end());
        std::multiset<char> msetTwo(t.begin(),t.end());
        if(msetOne == msetTwo)
            return true;

        return false;
    }
};
