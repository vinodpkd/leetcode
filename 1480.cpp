//1480. Running Sum of 1d Array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::vector<int> rsum(nums.size());
        int sum_now{0};
        for(auto i = 0;i < nums.size();i++)
        {
            //int sum_now = std::accumulate(nums.begin(),nums.begin()+i+1,0);
            sum_now += nums[i];
            rsum[i] = sum_now;
        }
        return rsum;
        }
};
