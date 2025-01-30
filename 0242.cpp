//242. Valid Anagram
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise. 
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.length())
            return false;
        //std::multiset<char> u(s.begin(),s.end());
        //std::multiset<char> v(t.begin(),t.end());
        
        //if(u == v)
        //    return true;

        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());

        if(s == t)
            return true;

        return false;
    }
};
---------------
#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // If the lengths are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Create a frequency array for 26 lowercase letters
        std::vector<int> freq(26, 0);

        // Increment frequency for characters in s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Decrement frequency for characters in t
        for (char c : t) {
            freq[c - 'a']--;
        }

        // If all frequencies are zero, the strings are anagrams
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
