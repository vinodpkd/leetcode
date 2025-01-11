//15. 3Sum
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int sum = 0;
        std::ranges::sort(v);

        vector<vector<int>> w{};
	
	for(int i = 0;i < v.size()-2;i++)
	{
		int j = i+1;
		int k = v.size()-1;
		
		while(j < k)
		{
			if(v[j] + v[k] == sum - v[i])
			{
                std::vector<int> t{v[i],v[j],v[k]};
                w.push_back(t);
				//std::cout << i << ' ' << j << ' ' << k << '\n';
				//break;
                j++;
                k--;
				//exit(0);
			}
			else if (v[j] + v[k] > sum - v[i])
			{
				k--;
			}
			else
			{
				j++;
			}
		}
        
	}
    std::set<std::vector<int>> x(w.begin(),w.end());
    std::vector<std::vector<int>> y(x.begin(),x.end());
    return y;
    }
};
