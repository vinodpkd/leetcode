//3168. Minimum Number of Chairs in a Waiting Room
/*
You are given a string s. Simulate events at each second i:
    If s[i] == 'E', a person enters the waiting room and takes one of the chairs in it.
    If s[i] == 'L', a person leaves the waiting room, freeing up a chair.
Return the minimum number of chairs needed so that a chair is available for every person who enters the waiting room given that it is initially empty.
*/
class Solution {
public:
    int minimumChairs(string s) {
        int max{0};
        int ch{0};
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == 'E')
            {
                ch++;
                if(max < ch)
                    max = ch;
            }
            else
            {
                ch--;
            }
        }

        return max;
        
    }
};
