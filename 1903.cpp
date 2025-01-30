//1903. Largest Odd Number in String
/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.
*/
class Solution {
public:
    string largestOddNumber(string num) {
        for(auto it = num.rbegin(); it != num.rend();it++)
        {
            std::string u(1,*it);
            int i = std::stoi(u);
            if(i % 2 == 1)
            {
                int j = std::distance(num.rbegin(),it);
                string t(num.begin(),num.begin()+num.size()-j);
                return t;
            }
        }
        return "";
    }
};

----------------
class Solution {
public:
    string largestOddNumber(string num) {
        // Iterate from the end of the string
        for (int i = num.length() - 1; i >= 0; --i) {
            // Check if the current character is an odd digit
            if ((num[i] - '0') % 2 != 0) {
                // Return the substring from the start to the current position
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit is found, return an empty string
        return "";
    }
};
---------------
    class Solution {
public:
    string largestOddNumber(string num) {
        for(auto it = num.rbegin(); it != num.rend();it++)
        {
            //std::string u(1,*it);
            //int i = std::stoi(u);
            int i = *it - '0';
            if(i % 2 == 1)
            {
                int j = std::distance(num.rbegin(),it);
                //string t(num.begin(),num.begin()+num.size()-j);
                return num.substr(0,num.size()-j);
            }
        }
        return "";
    }
};
