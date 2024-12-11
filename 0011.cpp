//11. Container With Most Water
/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
	int right = height.size() - 1;
	
	int maxWater = 0;
	
	while(left <= right)
	{
		int currArea = std::min(height[left],height[right])*(right-left);
		
		if(maxWater < currArea)
		{
			maxWater = currArea;
		}
		
		if(height[left] > height[right])
		{
			right--;
		}
		else
		{
			left++;
		}
	}    

	return maxWater;
    }
};

---------------------
  I'll solve the "Container With Most Water" problem in C++ and provide a detailed explanation of the 
solution. This problem is typically solved using the Two Pointer technique.

Problem Statement:
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n 
vertical lines are drawn such that the two endpoints of the line are at (i, ai) and (i, 0). Find two lines, 
which, together with the x-axis forms a container, such that the container contains the most water.

Here's a C++ solution with a detailed explanation:

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize two pointers
        int left = 0;
        int right = height.size() - 1;
        
        // Variable to store the maximum water area
        int maxWater = 0;
        
        // Continue until the pointers meet
        while (left < right) {
            // Calculate the width between the two lines
            int width = right - left;
            
            // Calculate the height (limited by the shorter line)
            int containerHeight = min(height[left], height[right]);
            
            // Calculate the area of water
            int currentArea = width * containerHeight;
            
            // Update maximum water area if current area is larger
            maxWater = max(maxWater, currentArea);
            
            // Move the pointer of the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};

```

Detailed Explanation:

1. **Two Pointer Approach**:
   - We start with two pointers: `left` at the beginning of the array and `right` at the end.
   - This allows us to consider the widest possible container first.

2. **Area Calculation**:
   - The water container's area is calculated by: `width * height`
   - `width` is the distance between the two lines (difference in indices)
   - `height` is the minimum of the two line heights (limited by the shorter line)

3. **Pointer Movement Strategy**:
   - We always move the pointer with the shorter line inward.
   - The reasoning is that to potentially increase the area, we need to find a taller line.
   - Moving the shorter line's pointer gives us a chance to find a taller line.

4. **Algorithm Steps**:
   - Initialize `left` to 0 and `right` to the last index
   - Initialize `maxWater` to store the maximum water area
   - While `left` is less than `right`:
     * Calculate the current container width
     * Find the container height (minimum of the two lines)
     * Calculate the current area
     * Update `maxWater` if the current area is larger
     * Move the pointer of the shorter line

5. **Time and Space Complexity**:
   - Time Complexity: O(n), where n is the number of lines
   - Space Complexity: O(1), as we only use a constant amount of extra space

**Example**:
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The maximum water area is between lines at index 1 and 8 
             (height 8 and 7), with a width of 7 and height of 7, so area is 49.
```

Key Insights:
- The two-pointer technique allows us to efficiently explore all possible containers.
- We start with the widest container and progressively narrow down.
- By always moving the shorter line's pointer, we ensure we don't miss the maximum possible area.

The solution elegantly solves the problem with a single pass through the array, making it both time and 
space efficient.

Would you like me to elaborate on any part of the solution or explain the algorithm in more depth?
