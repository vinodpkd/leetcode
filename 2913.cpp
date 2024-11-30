//2913. Subarrays Distinct Element Sum of Squares I
/*
You are given a 0-indexed integer array nums.
The distinct count of a subarray of nums is defined as:
    Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
Return the sum of the squares of distinct counts of all subarrays of nums.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sqsum{0};
        for(int i = 0;i < nums.size();i++)
        {
            for(int j = i;j < nums.size();j++)
            {
                std::set<int> u(nums.begin()+i,nums.begin()+j+1);
                sqsum += u.size()*u.size();
            }
        }

        return sqsum;
    }
};
