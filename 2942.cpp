//2942. Find Words Containing Character
/*
You are given a 0-indexed array of strings words and a character x.
Return an array of indices representing the words that contain the character x.
Note that the returned array may be in any order.
*/
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        std::vector<int> occur{};
        for(int i = 0;i < words.size();i++)
        {
            int j = words[i].find(x);
            if(-1 != j)
                occur.push_back(i);               
        }

        return occur;
    }
};
