#383. Ransom Note
/*
  Given two strings ransomNote and magazine, return true if ransomNote can be constructed 
  by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::multiset<char> rn(ransomNote.begin(),ransomNote.end());
        std::multiset<char> mg(magazine.begin(),magazine.end());
        std::multiset<char> intersection;
std::set_intersection(rn.begin(), rn.end(), mg.begin(), mg.end(), std::inserter(intersection, intersection.begin()));

    if(intersection == rn)
        return true;
    return false;
        
    }
};
