//2785. Sort Vowels in a String
/*
Given a 0-indexed string s, permute s to get a new string t such that:
    All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
    The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.
*/
class Solution {
public:
    string sortVowels(string s) {
        std::string vowels{"aeiouAEIOU"};
        std::vector<int> vp{};
        std::vector<char> vc{};

        for(int i = 0;i < s.size();i++)
        {
            if(vowels.find(s[i]) != -1)
            {
                vc.push_back(s[i]);
                vp.push_back(i);
            }
                
        }

        std::sort(vc.begin(),vc.end());

        for(int i = 0;i < vc.size();i++)
        {
            s[vp[i]] = vc[i];
        }

        return s;
        
    }
};
