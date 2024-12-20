461. Hamming Distance
/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them.
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        std::string m = std::bitset<32>(x).to_string();
        std::string n = std::bitset<32>(y).to_string();

        int d{0};

        for(int i = 0;i < m.size();i++)
        {
            if(m[i] != n[i])
                d++;
        }

        return d;
    }
};
