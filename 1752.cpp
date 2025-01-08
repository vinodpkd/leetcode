//1752. Check if Array Is Sorted and Rotated
/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;  // Count of points where nums[i] > nums[i+1]
        int n = nums.size();
        
        // Check each adjacent pair, including the wrap-around
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        // If count <= 1, the array can be sorted and rotated
        return count <= 1;
    }
};

Let's break down how this works:

    We keep track of the number of points where the array is not in ascending order (count).
    We iterate through the array and compare each element with the next element (using modulo for wrap-around).
    If we find a point where current element is greater than the next element, we increment count.
    Finally, we check if count <= 1:
        If count = 0: Array is already sorted
        If count = 1: Array is sorted and rotated
        If count > 1: Array cannot be sorted and rotated

Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) as we only use a constant amount of extra space

Example:

    For array [3,4,5,1,2]:
        At index 2: 5 > 1, count becomes 1
        No other violations found
        Returns true as count = 1
    For array [2,1,3,4]:
        At index 0: 2 > 1, count becomes 1
        At index 1: 1 < 3, no increment
        At index 3: 4 > 2 (wrap around), count becomes 2
        Returns false as count = 2

-------------


class Solution {
public:
    bool check(vector<int>& nums) {
        bool asc = std::ranges::is_sorted(nums);
        if(true == asc)
            return true;
        bool desc = std::ranges::is_sorted(nums,std::greater<>{});
        if(true == desc)
            return true;
        auto it = std::ranges::is_sorted_until(nums);
        int diff = *(it - 1) - nums[0];
        std::cout << diff << ' ' << std::distance(nums.begin(),it) << '\n';
        if(diff < 0)
            return false;
        bool sorted = std::is_sorted(it,nums.end());
        if(sorted == true)
            return true;
        return false;
    }
};
