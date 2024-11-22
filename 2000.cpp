//2000. Reverse Prefix of Word
/*
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.
 For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.
*/
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch);
        string s = "";
        for(int j = i;j >= 0;j--)
            s = s + word[j];

        for(int j = i+1;j < word.size();j++)
            s = s + word[j];


        return s;
    }
};
