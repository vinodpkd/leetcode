//2744. Find Maximum Number of String Pairs
/*
You are given a 0-indexed array words consisting of distinct strings.
The string words[i] can be paired with the string words[j] if:
    The string words[i] is equal to the reversed string of words[j].
    0 <= i < j < words.length.
Return the maximum number of pairs that can be formed from the array words.
Note that each string can belong in at most one pair.
*/
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count{0};
        for(int i = 0;i < words.size();i++)
        {
            for(int j = i+1;j < words.size();j++)
            {
                std::string s1{words[j]};
                std::reverse(s1.begin(),s1.end());
                if(s1 == words[i])
                    count++;
            }
        }
        return count;
    }
};
