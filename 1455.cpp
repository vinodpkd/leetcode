//1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
/*
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.
Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.
A prefix of a string s is any leading contiguous substring of s.
*/
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        std::vector<std::string> words = split(sentence," ");
        for(int i = 0;i < words.size();i++)
        {
            int p = words[i].find(searchWord);
            if(0 == p)
                return i+1;
        }
        return -1;
        /*
        int i = 1;
        int j = 0;
        while(j < sentence.length())
        {
            
            if(' ' == sentence[j])
            {
                i++;
                j++;
                continue;
            }   
            if(sentence[j] == searchWord[0] && ((i == 1) || sentence[j-1] == ' '))
            {
                int k = 1;
                j++;
                while(k < searchWord.size() && sentence[j] == searchWord[k])
                {
                    k++;
                    j++;
                }
                if(searchWord.size() - 1 == k)
                    return true;
            }
            else
            {
                j++;
            }
            
        }

        return -1;
        */
    }

    std::vector<std::string> split(std::string s, std::string delimiter) {
	//initialization of variables need not be in the end.
	//string.size() == string.length()
	/*
As per the documentation, these are just synonyms. size() is there to be consistent with other STL containers (like vector, 
map, etc.) and length() is to be consistent with most peoples' intuitive notion of character strings. People usually talk 
about a word, sentence or paragraph's length, not its size, so length() is there to make things more readable.
*/
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
	/*
	That line of code searches for the first occurrence of a delimiter within a C++ string, starting from a specified 
position. Let's break it down:
    s.find(delimiter, pos_start): This part uses the find() method of the std::string class. It searches for the first 
occurrence of the delimiter string within the string s. The search begins at the index pos_start. 
pos_end = ...: This assigns the result of the find() operation to the variable pos_end.

The Result: The find() method returns the index (position) of the first character of the found delimiter. If the delimiter is 
not found, it returns std::string::npos, a special constant typically representing the maximum value of the size_t type.
	*/

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
};
