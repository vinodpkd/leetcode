//47. Permutations II

/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> perm{};
        do
        {
            perm.push_back(nums);
        }while(std::next_permutation(nums.begin(),nums.end()));

        return perm;
    }
};
