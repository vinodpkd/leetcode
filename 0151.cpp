//151. Reverse Words in a String
/*
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/
class Solution {
public:
    string reverseWords(string s) {
        s.erase(s.find_last_not_of(" \n\r\t")+1);
        std::reverse(s.begin(),s.end());
        s.erase(s.find_last_not_of(" \n\r\t")+1);
        std::reverse(s.begin(),s.end());
        
        
        std::vector<std::string> r = split(s, " ");
        s.erase(s.find_last_not_of(" \n\r\t")+1);
        std::reverse(r.begin(),r.end());
        for(auto& x : r)
            std::cout << x << ' ';
        std::cout << '\n';
        std::string t{r[0]};
        std::cout << t << '\n';
        for(int i = 1;i < r.size();i++)
        {
            t = t + " " + r[i];
        }
        return t;
    }

    std::vector<std::string> split(std::string s, std::string delimiter) {
    std::vector<std::string> res;
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    
    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        // Only add non-empty tokens
        if (pos_end > pos_start) {
            res.push_back(s.substr(pos_start, pos_end - pos_start));
        }
        pos_start = pos_end + delim_len;
    }
    
    // Add the last token if it's not empty
    if (pos_start < s.length()) {
        res.push_back(s.substr(pos_start));
    }
    
    return res;
}
};
