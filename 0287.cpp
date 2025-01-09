//287. Find the Duplicate Number
/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space. 
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::ranges::sort(nums);
        for(int i = 1;i < nums.size();i++)
        {
            if(nums[i] == nums[i-1])
                return nums[i];
        } 

        return nums[0];
    }
};
-----------------
    class Solution {
public:
    // Floyd's Cycle Detection (Tortoise and Hare)
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Finding intersection point inside the cycle
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Phase 2: Finding the entrance to the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
    // Alternative Solution: Binary Search approach
    int findDuplicateBinarySearch(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            
            // Count numbers less than or equal to mid
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            
            // If count is more than mid, duplicate is in left half
            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
