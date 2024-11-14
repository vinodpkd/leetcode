//2190 Most Frequent Number Following Key In an Array,beats 100% in time
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        std::map<int,int> dict{};
        int i = 0;
        int maxm = 0;
        int maxmelem;
        while(i < (nums.size() - 1))
        {
            if(key == nums[i])
            {
                dict[nums[i+1]]++;
                if(maxm < dict[nums[i+1]])
                {maxm = dict[nums[i+1]];maxmelem = nums[i+1];}                
            }
            i++;
        }

        return maxmelem;
    }
};
