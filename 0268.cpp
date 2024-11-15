//268. Missing Number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::multiset mset(nums.begin(),nums.end());
        for(int i = 0;i <= nums.size();i++)
        {
            auto it = std::find(mset.begin(), mset.end(), i);
            if(it == mset.end())
                return i;
        }
        return -1;
    }
};
