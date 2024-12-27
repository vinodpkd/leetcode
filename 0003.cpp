//3. Longest Substring Without Repeating Characters
/*
Given a string s, find the length of the longest substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(0 == s.length())
            return 0;

         
        int maxlen = 1;
        int start = 0, end = 0;
        std::unordered_set<int> chars{};
        for(int i = 0;i < s.length();i++)
        {
            if(chars.count(s[i]) == 0)
            {
                chars.insert(s[i]);
            }
            else
            {
                end = i - 1;
                start = i - chars.size();
                maxlen = std::max(maxlen,end-start+1);
                auto it = std::find(s.begin()+start,s.begin()+i,s[i]);
                int d = std::distance(s.begin()+start,it);
                chars.clear();
                //std::copy(it,s.begin()+i,chars.begin());
                while(it < s.begin()+i)
                {
                    chars.insert(*it);
                    it++;
                }
            }
        }

        if(chars.size() == s.length())
            return s.length();
        return std::max(maxlen,(int)chars.size());
    }
};
