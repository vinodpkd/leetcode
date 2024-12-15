16. 3Sum 
The 3Sum Closest problem asks you to find three numbers in a given array whose sum is closest to a target value.  Here's how to solve it efficiently in C++, along with explanations:

### Algorithm

1. **Sort the Array:** Sorting the input array `nums` allows for efficient two-pointer traversal in the next step.  This sorting step takes O(n log n) time.

2. **Two-Pointer Approach:** Iterate through the sorted array using a single pointer `i`. For each `nums[i]`, use two pointers, `j` and `k`, to explore the remaining array.  `j` starts at `i + 1` and `k` starts at the end of the array (`nums.size() - 1`).

3. **Sum and Compare:** Calculate the sum `currentSum = nums[i] + nums[j] + nums[k]`. Compare `currentSum` to the target `target` and update the `closestSum` if `currentSum` is closer to `target` than the current `closestSum`.

4. **Adjust Pointers:** Based on the comparison, adjust the `j` and `k` pointers:
   - If `currentSum < target`, move `j` to the right (`j++`) to increase the sum.
   - If `currentSum > target`, move `k` to the left (`k--`) to decrease the sum.
   - If `currentSum == target`, you've found the exact sum, so return `target`.

5. **Return Closest Sum:** After iterating through all possible triplets, return the `closestSum`.

### C++ Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // Required for numeric_limits

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    // Sort the array
    sort(nums.begin(), nums.end());

    int closestSum = numeric_limits<int>::max(); // Initialize with the largest possible integer
    int minDifference = numeric_limits<int>::max(); // Initialize with the largest possible integer

    for (int i = 0; i < nums.size() - 2; ++i) {
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int currentSum = nums[i] + nums[j] + nums[k];
            int difference = abs(currentSum - target);

            if (difference < minDifference) {
                minDifference = difference;
                closestSum = currentSum;
            }

            if (currentSum < target) {
                j++;
            } else if (currentSum > target) {
                k--;
            } else {
                return target; // Exact match found
            }
        }
    }

    return closestSum;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, target);
    cout << "The closest sum is: " << result << endl; // Output: 2

    return 0;
}
```

### Time and Space Complexity

- **Time Complexity:** O(n^2), dominated by the nested loops in the two-pointer approach. The initial sorting takes O(n log n), but this is less significant than the nested loops for larger input sizes.
- **Space Complexity:** O(1) (constant space), as we are modifying the input array in place and using only a few extra variables.


This optimized approach significantly improves the efficiency compared to a brute-force solution, which would have a time complexity of O(n^3).  The use of `numeric_limits<int>::max()` ensures correct initialization even with edge cases. Remember to include `<limits>` for this to work.
