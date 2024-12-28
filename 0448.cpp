//448. Find All Numbers Disappeared in an Array
/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> res(nums.size());
        std::iota(res.begin(),res.end(),1);
        std::set<int> s1(res.begin(),res.end());
        std::set<int> s2(nums.begin(),nums.end());
        std::vector<int> d{};
        std::set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),std::back_inserter(d));
        return d;
        /*
        for(int i = 0;i < nums.size();i++)
        {
            res.erase(std::remove(res.begin(), res.end(), nums[i]), res.end());
        }
        return res;
        */

    }
};
