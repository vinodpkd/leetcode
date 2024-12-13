//2965. Find Missing and Repeated Values
/*
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
*/
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        std::vector<int> v{grid[0]};
        for(int i = 1;i < grid.size();i++)
        {
            v.insert(v.end(),grid[i].begin(),grid[i].end());
        }

        std::multiset<int> mset(v.begin(),v.end());
        std::set<int> set1(v.begin(),v.end());

        std::vector<int> repeated{};
        std::set_difference(mset.begin(),mset.end(),set1.begin(),set1.end(),std::back_inserter(repeated));
        int n = grid.size();
        int gsum = (n*n)*(n*n + 1)/2;
        int sum = std::accumulate(set1.begin(),set1.end(),0);
        int missing = gsum - sum;
        std::vector<int> res{repeated[0],missing};
        return res;

        
    }
};
