//3158. Find the XOR of Numbers Which Appear Twice
/*
You are given an array nums, where each number in the array appears either once or twice.
Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.
*/
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        std::multiset<int> mset(nums.begin(),nums.end());
        std::set<int> set(nums.begin(),nums.end());
        std::vector<int> differenceSet{};
std::set_difference(mset.begin(), mset.end(), set.begin(), set.end(), 
                        std::back_inserter(differenceSet));
        if(differenceSet.size() == 0)
            return 0;

         if(differenceSet.size() == 1)
            return differenceSet[0];

        int xorsum = differenceSet[0];

        for(int i = 1;i < differenceSet.size();i++)
        {
            xorsum = xorsum ^ differenceSet[i];
        }

        return xorsum;
    }
};
