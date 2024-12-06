//344. Reverse String
/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0;i < s.size()/2;i++)
        {
            std::swap(s[i],s[s.size()-1-i]);
        }
        
    }
};
