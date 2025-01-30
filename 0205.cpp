//205. Isomorphic Strings
/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, char> s_to_t;
    std::unordered_map<char, char> t_to_s;

    for (size_t i = 0; i < s.length(); ++i) {
        char char_s = s[i];
        char char_t = t[i];

        // Check if the character from s has been mapped before
        if (s_to_t.find(char_s) != s_to_t.end()) {
            if (s_to_t[char_s] != char_t) {
                return false;
            }
        } else {
            // Check if the character from t has been mapped to another character in s
            if (t_to_s.find(char_t) != t_to_s.end()) {
                return false;
            }

            // Create new mapping
            s_to_t[char_s] = char_t;
            t_to_s[char_t] = char_s;
        }
    }

    return true;
    }
};
