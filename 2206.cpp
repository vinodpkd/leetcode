/*
2206. Divide Array Into Equal Pairs
You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

    Each element belongs to exactly one pair.
    The elements present in a pair are equal.

Return true if nums can be divided into n pairs, otherwise return false.
*/
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        std::unordered_map<int, int> frequency;

    // Count the frequency of each number
    for (int num : nums) {
        frequency[num]++;
    }

    // Check if all frequencies are even
    for (const auto& pair : frequency) {
        if (pair.second % 2 != 0) {
            return false; // If any frequency is odd, return false
        }
    }

    return true; // All frequencies are even, return true
        /*
        std::set<int> s(nums.begin(),nums.end());
        for(int x : s)
        {
            int c = std::count(nums.begin(),nums.end(),x);
            if(0 != (c%2))
                return false;
        }
        return true;
        */
    }
};
