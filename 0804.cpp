//804. Unique Morse Code Words
/*
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.
*/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        std::string alpha {"abcdefghijklmnopqrstuvwxyz"};
        std::vector<std::string> codes {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        std::set<std::string> codeset{};

        for(int i = 0;i < words.size();i++)
        {
            std::string codenow{};

            for(int j = 0;j < words[i].size();j++)
            {
                int index = alpha.find(words[i][j]);
                codenow = codenow + codes[index];

            }

            codeset.insert(codenow);
        }

        return codeset.size();
    }
};
