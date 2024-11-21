//1365. How Many Numbers Are Smaller Than the Current Number
/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
Return the answer in an array.
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::vector<int> countless(nums.size(),0);
        for(int i = 0;i < nums.size();i++)
        {
            int num_now = nums[i];
            int count = std::count_if(nums.begin(),nums.end(),[num_now](int a){return a < num_now;});
            countless[i] = count;
        }

        return countless;
    }
};
