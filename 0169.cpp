//Majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int,int> dict {};
        int max = 0, maj;
        for(int i = 0;i < nums.size();i++)
        {
            
                dict[nums[i]]++;
                if(dict[nums[i]] > max )
                {
                    max = dict[nums[i]];
                    maj = nums[i];
                    
                }
            
        }

        return maj;
    }
};
