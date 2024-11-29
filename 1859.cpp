//1859. Sorting the Sentence
/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
    For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence. 
*/
class Solution {
public:
    string sortSentence(string s) {

        if(s.length() == 0)
            return s;

        std::vector<std::string> words = split(s," ");

        std::vector<std::string> d(words.size());

        for(int i = 0;i < words.size();i++)
        {
            int k = words[i].size();
            std::string c{words[i][k-1]};
            int j = std::stoi(c);
            std::string w{words[i].substr(0,k-1)};
            //std::cout << w << '\n';
            d[j-1] = w;
        }

        std::string ds {};

        for(int j = 0;j < d.size()-1;j++)
        {
            ds = ds + d[j] + " ";
        }

        ds = ds + d[d.size()-1];

        return ds;
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
