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
--------------
class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        std::unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Create a vector of characters
        std::vector<char> chars;
        for (auto& pair : freqMap) {
            chars.push_back(pair.first);
        }

        // Step 3: Sort the characters based on their frequency in descending order
        std::sort(chars.begin(), chars.end(), [&](char a, char b) {
            return freqMap[a] > freqMap[b];
        });

        // Step 4: Build the result string
        std::string result;
        for (char c : chars) {
            result.append(freqMap[c], c); // Append the character 'c' freqMap[c] times
        }

        return result;
    }
};
