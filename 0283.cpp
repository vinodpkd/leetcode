//283. Move Zeroes
/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int count = std::count_if(nums.begin(),nums.end(),[](int n){return n == 0;});

        auto end = std::remove(nums.begin(), nums.end(), 0);
        nums.erase(end, nums.end());
        for(int i = 0;i < count;i++)
            nums.push_back(0);
        
    }
};
