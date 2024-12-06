//345. Reverse Vowels of a String
/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/
class Solution {
public:
    string reverseVowels(string s) {
        std::set<char> v{'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            while(v.count(s[i]) == 0)
            {
                i++;
                if(i > (s.size()-1))
                    break;
            }
                
            while(v.count(s[j]) == 0)
            {
                j--;
                if(j < 0)
                    break;
            }

            if(i >= j)
                break;
                
            std::cout << i << " " << s[i] << ' ' << j << ' ' << s[j] << '\n';
            std::swap(s[i],s[j]);
            i++;j--;
        }

        return s;
    }
};
