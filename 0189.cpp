//189. Rotate Array
/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k != 0)
            k = k % nums.size();
        std::rotate(nums.begin(), std::prev(nums.end(), k), nums.end());
    }
};
