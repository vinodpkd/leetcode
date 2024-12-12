//2529. Maximum Count of Positive Integer and Negative Integer
/*
Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
    In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.
*/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int mp{0},mn{0};
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] < 0)
            {
                mn++;
            }
            else if(nums[i] > 0)
            {
                mp++;
            }
        }

        return std::max(mn,mp);
    }
};
