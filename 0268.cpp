//268. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int s = std::accumulate(nums.begin(),nums.end(),0);
       int gsum = (nums.size())*(nums.size()+1)/2;
       return gsum - s;
    }
};
