//35. Search Insert Position, Beats 100.00%


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto lower = std::lower_bound(nums.begin(),nums.end(),target);
        int index = std::distance(nums.begin(), lower);
        return index;
    }
};
