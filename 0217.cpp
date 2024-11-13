//217 Contains duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int,int> dict {};
        for(int i = 0;i < nums.size();i++)
        {
            dict[nums[i]]++;
            if(dict[nums[i]] > 1)
                return true;
        }

        return false;
        
    }
};
