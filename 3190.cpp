//3190. Find Minimum Operations to Make All Elements Divisible by Three
//You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.
//Return the minimum number of operations to make all elements of nums divisible by 3.
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int count = std::count_if(nums.begin(), nums.end(), [](int num) { return num % 3 == 0; });
         return nums.size() - count;
         //return std::count_if(nums.begin(), nums.end(), [](int num) { return num % 3 != 0; });
    }
};
