//67. Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        unsigned int i = std::stoi(a, nullptr, 2);
        unsigned int j = std::stoi(b, nullptr, 2);
        i = i+j;
        string c = std::bitset<128>(i).to_string();
        size_t firstOne = c.find_first_not_of('0');
        return (firstOne == std::string::npos) ? "0" : c.substr(firstOne);

    }
};
