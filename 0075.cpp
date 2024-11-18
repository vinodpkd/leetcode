//75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::multiset mset(nums.begin(),nums.end());
        nums.clear();
        for(auto it = mset.begin();it != mset.end();++it)
            nums.push_back(*it);
    }
};
