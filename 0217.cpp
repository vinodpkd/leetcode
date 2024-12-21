//217 Contains duplicate
/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int size = nums.size();
        std::sort(nums.begin(),nums.end());
        auto it = std::unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());
        //for(int& x : nums)
        //    std::cout << x << ' ';
        //std::cout << '\n';
        if(size == nums.size())
            return false;
        
        return true;
       /*
            
        std::map<int,int> dict {};
        for(int i = 0;i < nums.size();i++)
        {
            dict[nums[i]]++;
            if(dict[nums[i]] > 1)
                return true;
        }

        return false;
        */
        
    }
};
