//771. Jewels and Stones
/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. 
Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        std::set<char> jset (jewels.begin(),jewels.end());

        int jewelcount = 0;
        for(int i = 0;i < stones.size();i++)
        {
            if(jset.find(stones[i]) != jset.end())
                jewelcount++;
        }

        return jewelcount;
    }
};
