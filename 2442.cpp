//2442. Count Number of Distinct Integers After Reverse Operations
/*
You are given an array nums consisting of positive integers.
You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
Return the number of distinct integers in the final array.
*/

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0;i < size;i++)
        {
            std::string s = std::to_string(nums[i]);
            std::reverse(s.begin(),s.end());
            int j = std::stoi(s);
            nums.push_back(j);
        }

        std::set<int> set1(nums.begin(),nums.end());
        return set1.size();
    }
};
