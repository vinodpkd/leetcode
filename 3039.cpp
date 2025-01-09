//3039. Apply Operations to Make String Empty
/*
You are given a string s.
Consider performing the following operation until s becomes empty:
For every alphabet character from 'a' to 'z', remove the first occurrence of that character in s (if it exists).
For example, let initially s = "aabcbbca". We do the following operations:
Remove the underlined characters s = "aabcbbca". The resulting string is s = "abbca".
Remove the underlined characters s = "abbca". The resulting string is s = "ba".
Remove the underlined characters s = "ba". The resulting string is s = "".
Return the value of the string s right before applying the last operation. In the example above, answer is "ba". 
*/
class Solution {
public:
    string lastNonEmptyString(string s) {
		vector<int> lastPos(26, -1);  // Track last position of each char
        vector<int> count(26, 0);     // Track frequency of each char
        
        // Count frequencies and last positions
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            lastPos[s[i] - 'a'] = i;
        }
        
        // Find the maximum frequency
        int maxFreq = *max_element(count.begin(), count.end());
        maxFreq--;  // We want chars that will remain after removing maxFreq times
        
        string result;
        // Store pairs of {position, char} for chars with max frequency
        vector<pair<int, char>> chars;
        
        for (int i = 0; i < 26; i++) {
            if (count[i] == maxFreq + 1) {
                chars.push_back({lastPos[i], (char)(i + 'a')});
            }
        }
        
        // Sort by position to maintain relative order
        sort(chars.begin(), chars.end());
        
        // Build result string
        for (const auto& p : chars) {
            result += p.second;
        }
        
        return result;
	}
};		
		
		
		class Solution {
public:
    string lastNonEmptyString(string s) {
        std::string a{"abcdefghijklmnopqrstuvwxyz"};
        std::string t;
        while(s != "")
        {
            t = s;
            for(char c : a)
            {
                int i = s.find(c);
                if(-1 != i)
                {
                    s.erase(s.begin()+i);
                }
            }

        }
        return t;
    }
};
