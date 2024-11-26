//2161. Partition Array According to Given Pivot
/*
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        if(std::is_sorted(nums.begin(),nums.end()))
            return nums;
        std::vector<int> left{};
        std::vector<int> right{};

        
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] < pivot)
            {
                left.push_back(nums[i]);
            }

            if(nums[i] == pivot)
                right.insert(right.begin(),pivot);

            if(nums[i] > pivot)
                right.push_back(nums[i]);
        }

        left.insert(left.end(),right.begin(),right.end());
        return left;
    }
};
