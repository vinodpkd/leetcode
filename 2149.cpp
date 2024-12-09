//2149. Rearrange Array Elements by Sign
/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
You should return the array of nums such that the the array follows the given conditions:
    Every consecutive pair of integers have opposite signs.
    For all integers with the same sign, the order in which they were present in nums is preserved.
    The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::stable_partition(nums.begin(),nums.end(),[](int c){return c < 0;});
        std::vector<int> tail(nums.size()/2,0);
        std::copy(nums.begin() + nums.size()/2, nums.end(),tail.begin());
        nums.resize(nums.size()/2);
        tail.resize(nums.size());
        int size = nums.size();
        for(int i = 0;i < size;i++)
        {
            tail.insert(tail.begin()+2*i+1,nums[i]);
        }

        return tail;
    }
};
