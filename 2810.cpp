//2810. Faulty Keyboard
/*
Your laptop keyboard is faulty, and whenever you type a character 'i' on it, it reverses the string that you have written. Typing other characters works as expected.
You are given a 0-indexed string s, and you type each character of s using your faulty keyboard.
Return the final string that will be present on your laptop screen.
*/

class Solution {
public:
    string finalString(string s) {
        std::string t{};
        int i = 0;
        bool endflag = false;
        int endindex = 0;
        for(int i = 0;i < s.size();i++)
        {
            if('i' != s[i] )
            {
                if(false == endflag)
                    t += s[i];
                else
                {
                    endindex = i;
                    for(int j = i;j < s.size();j++)
                        t = t + s[j];
                    break;
                }
                    
            }
                
            else
            {
                endflag = true;
                std::reverse(t.begin(),t.end());
            }

        }

        int count = std::count_if(t.begin(),t.end(),[](char c){return c == 'i';});
        if (count > 0)
            t = finalString(t);
        
        return t;
    }
};
