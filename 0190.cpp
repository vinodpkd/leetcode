//Reverse bits of a given 32 bits signed integer.
//0ms Beats 100.00%

class Solution {
public:
    int reverseBits(int n) {
        std::bitset<32> b(n);
        for(int i = 0;i < 16;i++)
        {
            if(b[i] == b[31-i])
                continue;
            else
            {
                b.flip(i);
                b.flip(31-i);
            }
        }
        int m;
        m = (int)(b.to_ulong());
        return m;
    }
};
