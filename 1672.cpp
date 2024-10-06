#include <numeric>
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = std::accumulate(accounts[0].begin(), accounts[0].end(), 0);
        for(size_t i = 1; i < accounts.size(); i++)
        {
            int sum = std::accumulate(accounts[i].begin(), accounts[i].end(), 0);
            if(sum > max)
                max = sum;
        }
        
        return max;
    }
};
