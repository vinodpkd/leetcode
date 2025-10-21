//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//You must implement a solution with a linear runtime complexity and use only constant extra space.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum {0};
        for(int i = 0;i < nums.size();i++)
            sum ^= nums[i];
        return sum;
        
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       std::bitset<32> result;
    for (int num : nums) {
        result ^= std::bitset<32>(num);
    }
    // Convert back considering sign
    return static_cast<int>(result.to_ulong()); 
    }
};
