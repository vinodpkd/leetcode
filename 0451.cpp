//451. Sort Characters By Frequency
/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
*/
class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char,int> u{};
        for(char c : s)
            u[c]++;

        for(auto& [x,y] : u)
            std::cout << x << ':' << y << '\n';
         std::multimap<int,char> v{};
         for(auto& [a,b] : u)
            v.insert(std::make_pair(b,a));
        for(auto& [x,y] : v)
            std::cout << x << ':' << y << '\n';
        std::string w{""};
        for(auto it = v.rbegin();it != v.rend();it++)
        {
            std::string x(it->first,it->second);
            w = w + x;
            std::cout << x << '\n';
        }

        return w;
    }
};
