/*1929. Concatenation of Array
Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays.
Return the array ans.
  */
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> m{nums};
        m.insert(m.end(),nums.begin(),nums.end());
        return m;
        //nums.insert(nums.end(),nums.begin(),nums.end());
        //return nums;
    }
};
-------------
 class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.insert(nums.end(),nums.begin(),nums.end());
        return nums;
    }
};
