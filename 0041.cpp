//41. First Missing Positive
/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minm = 1;
        std::set<int> u{};
        for(int i = 0;i < nums.size();i++)
        {
            if(!u.contains(nums[i]) && nums[i] > 0)
            {
                u.insert(nums[i]);
            }
        }

        for(int x : u)
            std::cout << x << ' ';

        std::cout << '\n';

        if(!u.contains(1))
            return 1;
        else
        {
            auto it = u.begin();
            it++;
            while(it != u.end())
            {
                auto it2 = it;
                it2--;
                std::cout << *it2 << ' ' << *it << '\n';
                if(*it - *(it2) > 1)
                    return *it2+1;
                it++;
            }

            if(it == u.end())
                return *(it--)+1;
            
        }
        return 1;
    }
};
---------------------------
    class Solution {
public:
    // Main Solution: In-place array marking
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Modify array to handle negative numbers and zeros
        // Replace negative numbers and zeros with n+1 
        // (which is greater than any valid index)
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        
        // Step 2: Mark presence of numbers using index as hash key
        // Use negative marking to indicate presence
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        
        // Step 3: Find first missing positive number
        // First positive number indicates missing index+1
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        // If all numbers from 1 to n exist, return n+1
        return n + 1;
    }
    
    // Alternative Solution using partition (less optimal for space)
    int firstMissingPositivePartition(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Partition positive numbers to the left
        int positive_count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                swap(nums[positive_count], nums[i]);
                positive_count++;
            }
        }
        
        // Step 2: Mark presence of numbers in positive partition
        for (int i = 0; i < positive_count; i++) {
            int num = abs(nums[i]);
            if (num <= positive_count) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        
        // Step 3: Find first missing positive
        for (int i = 0; i < positive_count; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return positive_count + 1;
    }
};
