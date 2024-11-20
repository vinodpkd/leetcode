//1684. Count the Number of Consistent Strings
/*You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.
  */

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        std::set<char> allch(allowed.begin(),allowed.end());
        int count = 0;
        for(int i = 0;i < words.size();i++)
        {
            bool flag = true;
            for(int j = 0;j < words[i].size();j++)
            {
                if(allch.find(words[i][j]) == allch.end())
                {
                    flag = false;
                    break;
                }
            }

            if(true == flag)
                count++;
        }

        return count;
    }
};
