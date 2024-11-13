//229 Majority Element II
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::map<int,int> dict {};
        int max = 0, maj;
        for(int i = 0;i < nums.size();i++)
        {
            
                dict[nums[i]]++;               
            
        }

        std::vector<std::pair<int, int>> vec(dict.begin(), dict.end());

        std::sort(vec.begin(), vec.end(), [](const std::pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
  });

    std::vector<int> freq {};
    int i = 0;
  for (const auto& p : vec) {
    if(i < 3 && p.second > nums.size()/3) {freq.push_back(p.first);}
    i++;
  }
    return freq;
    }
};
