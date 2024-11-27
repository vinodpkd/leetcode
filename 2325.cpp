//2325. Decode the Message
/*
You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:
    Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
    Align the substitution table with the regular English alphabet.
    Each letter in message is then substituted using the table.
    Spaces ' ' are transformed to themselves.
    For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
  */

class Solution {
public:
    string decodeMessage(string key, string message) {
        std::set<int> st{};
        std::string s{};
        for(int i = 0;i < key.size();i++)
        {
            if(key[i] == ' ')
                continue;
            if(st.find(key[i]) == st.end())
            {
                st.insert(key[i]);
                s = s + key[i];
            }
                
        }

        std::string alpha{"abcdefghijklmnopqrstuvwxyz"};
        std::map<char,char> mp{};
        mp[' '] = ' ';
        int i = 0;
        while(i < s.size())
        {
            
                mp[s[i]] = alpha[i];
                i++;
             
        }

        std::string enc = message;
        for(int i = 0;i < message.size();i++)
        {
            enc[i] = mp[message[i]];
        }

        return enc;
    }
};
