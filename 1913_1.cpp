//1913. Maximum Product Difference Between Two Pairs
/*
The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
    For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.
Return the maximum such product difference. 
*/
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int size = nums.size();
        //std::sort(nums.begin(),nums.end());
        //return nums[size-1]*nums[size-2] - nums[0]*nums[1];
        auto it = std::max_element(nums.begin(),nums.end());
        int a = *it;
        nums.erase(it);
        it = std::max_element(nums.begin(),nums.end());
        int b = *it;
        nums.erase(it);
        it = std::min_element(nums.begin(),nums.end());
        int c = *it;
        nums.erase(it);
        int d = *std::min_element(nums.begin(),nums.end());
        
        return a*b - c*d;
        
    }
};
