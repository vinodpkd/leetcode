//137. Single Number II
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++)
        {
            int j = std::count(nums.begin(), nums.end(), nums[i]);
            if(1 == j)
                return nums[i];
        }

        return 0;
    }
};
