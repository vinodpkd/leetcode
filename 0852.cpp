#include <vector>
#include <algorithm>
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto it = std::is_sorted_until(arr.begin(),arr.end());
	
	int index = std::distance(arr.begin(), it) - 1;
    return index;
    }
};
