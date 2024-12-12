//2089. Find Target Indices After Sorting Array
/*
You are given a 0-indexed integer array nums and a target element target.
A target index is an index i such that nums[i] == target.
Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.
*/
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        auto i = std::lower_bound(nums.begin(),nums.end(),target);

        
        
        if(i != nums.end())
        {
            auto j = std::upper_bound(nums.begin(),nums.end(),target);
            int p = std::distance(nums.begin(),i);
            int q = std::distance(nums.begin(),j);
            //std::cout << p << ' ' << q << '\n';
            std::vector<int> res(q-p,0);
            std::iota(res.begin(),res.end(),p);
            return res;

        }
        std::vector<int> res{};
        return res;
        
        

    }
};
