//2220. Minimum Bit Flips to Convert Number
/*A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.
    For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.
*/
class Solution {
public:
    int minBitFlips(int start, int goal) {

        std::string s = std::bitset<128>(start).to_string();
        //size_t firstOne = c.find_first_not_of('0');
        //std::string s = (firstOne == std::string::npos) ? "0" : c.substr(firstOne);

        std::string g = std::bitset<128>(goal).to_string();
        //firstOne = d.find_first_not_of('0');
        //std::string g = (firstOne == std::string::npos) ? "0" : c.substr(firstOne);

        std::cout << "start = " << s << "  goal = " << g << '\n';

        if(g.size() != s.size())
            return 0;

        if(g == s)
            return 0;

        int changes{0};

        int i = 0;
        while(i < g.size())
        {
            if(g[i] != s[i])
                changes++;
            i++;
        }

        return changes;

    }
};
