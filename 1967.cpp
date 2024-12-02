//1967. Number of Strings That Appear as Substrings in Word
/*
*/
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count{0};
        for(int i = 0;i < patterns.size();i++)
        {
            if(-1 != word.find(patterns[i]))
            {
                count++;
            }
        }
        return count;
    }
};
