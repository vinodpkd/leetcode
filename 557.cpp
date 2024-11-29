//557. Reverse Words in a String III
/*Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.*/
class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string> t = split(s, " ");
        std::string u{};
        int i = 0;
        for(;i < t.size()-1;i++)
        {
            std::reverse(t[i].begin(),t[i].end());
            u = u + t[i] + " ";
        }
        std::reverse(t[i].begin(),t[i].end());
        u = u + t[i];
        return u;
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
