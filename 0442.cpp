//442. Find All Duplicates in an Array
/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output 
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::map<int,int> m{};
        std::vector<int> u{};
        for(int i = 0;i < nums.size();i++)
        {
            m[nums[i]]++;
            if(2 == m[nums[i]])
            {
                u.push_back(nums[i]);
            }
        }

        return u;

    }
};
