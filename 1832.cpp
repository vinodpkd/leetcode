//1832. Check if the Sentence Is Pangram
/*
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
  */
class Solution {
public:
    bool checkIfPangram(string sentence) {
        std::set<char> s(sentence.begin(),sentence.end());
        if(26 == s.size())
            return true;
        return false;
        
    }
};
