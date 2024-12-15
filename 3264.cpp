//3264. Final Array State After K Multiplication Operations I
/*
You are given an integer array nums, an integer k, and an integer multiplier.
You need to perform k operations on nums. In each operation:
    Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
    Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.
*/
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0;i < k;i++)
        {
            auto it = std::min_element(nums.begin(),nums.end());
            *it = *it * multiplier;
        }
        return nums;
    }
};
