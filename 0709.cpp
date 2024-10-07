class Solution {
public:
    string toLowerCase(string s) {
     for (auto& c: s) c = (char)tolower(c); 
     return  s;
    }
};
//https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
//GeePokey
/*
709. To Lower Case
Solved
Easy
Topics
Companies
Hint

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter
*/
