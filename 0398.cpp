//398. Random Pick Index
/*
Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
Implement the Solution class:
Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
*/
class Solution {
    private:
    std::vector<int> nums{};
    std::unordered_map<int,std::vector<int>> freq{};
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        for(int i = 0;i < nums.size();i++)
        {
            this->freq[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        // Define range
    int min = 0;
    int max = freq[target].size()-1;

    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    // Generate random number in the range [min, max]
    int randomIndex = distrib(gen);
    return this->freq[target][randomIndex];

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
