//1464. Maximum Product of Two Elements in an Array
/*
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1). 
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto it = std::max_element(nums.begin(),nums.end());
        int a = *it;
        nums.erase(it);
        it = std::max_element(nums.begin(),nums.end());
        int b = *it;
        nums.erase(it);

        return (a-1)*(b-1);
    }
};
