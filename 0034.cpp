//34. Find First and Last Position of Element in Sorted Array
/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!std::binary_search(nums.begin(), nums.end(), target))
        {
            std::vector<int> res{-1,-1};
            return res;
        }
        else
        {
            auto left = std::lower_bound(nums.begin(),nums.end(),target);
            int i = std::distance(nums.begin(),left);
            auto right = std::upper_bound(nums.begin(),nums.end(),target);
            int j = std::distance(nums.begin(),right);
            j--;
            std::vector<int> res{i,j};
            return res;
        }
    }
};
