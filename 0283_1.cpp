//283. Move Zeroes
/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
*/
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        int c{0};
        int i = 0;
        while(i+1 < nums.size())
        {
            if(nums[i] == nums[i+1] && nums[i] != 0)
            {
                nums[i] *= 2;
                nums.erase(nums.begin()+i+1);
                c++;
            }
            else
            {
                if(0 == nums[i])
                {
                    nums.erase(nums.begin()+i);
                    c++;
                    i--;
                }
            }
            i++;
        }
        std::vector<int> zeros(c,0);
        nums.insert(nums.end(),zeros.begin(),zeros.end());
        return nums;
    }
};
