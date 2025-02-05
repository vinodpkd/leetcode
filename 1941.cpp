//1941. Check if All Characters Have Equal Number of Occurrences
/*
Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
*/
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        std::unordered_map<char,int> m{};
        for(char c : s)
        {
            m[c]++;
        }
        std::set<int> st{};
        for(auto& [k,v] : m)
        {
            st.insert(v);
            if(st.size() > 1)
                return false;
        }
        return true;
    }
};
