//1913. Maximum Product Difference Between Two Pairs
/*
The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
    For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.
Return the maximum such product difference.
*/
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        std::vector<std::pair<int,int>> indices = getComb(nums.size());
        std::unordered_map<std::pair<int,int>,int> umap(indices.size());

        for(auto& p: indices)
        {
            umap[p] = nums[p.first]*nums[p.second];
        }
        int j = 0;
        int max = 0;

        for(int i = 0;i < indices.size();i++)
        {
            if(j == i && i == 0)
                max = umap[indices[0]];

            for(j = i;j < indices.size();j++)
            {
                int prod = umap[indices[i]] -  umap[indices[j]];

                if(max < prod)
                    max = prod;
                if(max < -prod)
                    max = -prod;
            }
        }

        return max;
    }

    std::vector<pair<int,int>> getComb(int n)
    {
        std::vector<pair<int,int>> comb{};

        for(int i = 0;i < n;i++)
        {
            for(int j = i;j < n;j++)
            {
                comb.push_back(std::make_pair(i,j));
            }
        }
        return comb;
    }
};
