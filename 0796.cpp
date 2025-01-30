//796. Rotate String
/*
  Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position
For example, if s = "abcde", then it will be "bcdea" after one shift.
 */
class Solution {
public:
    bool rotateString(string s, string goal) {
      if (s.length() != goal.length()) {
        return false;
    }

 // Concatenate s with itself
    std::string concatenated = goal + goal;

    // Check if goal is a substring of concatenated
    return concatenated.find(s) != std::string::npos;
    }
};
