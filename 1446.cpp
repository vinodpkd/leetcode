//1446. Consecutive Characters
/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.
Given a string s, return the power of s.
*/
class Solution {
public:
    int maxPower(string s) {
        int max{1};
        int i = 0;
        while(i < s.length())
        {
            if(s[i] == s[i+1])
            {   
                i++;
                int count = 2;
                while(s[i] == s[i+1])
                {
                    count++;
                    i++;
                }
                if(max < count)
                    max = count;
            }
            else
            {
                i++;
            }
        }

        return max;
    }
};
