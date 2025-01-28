//704. Binary Search

class Solution {
public:
    int search(vector<int>& arr, int target) {
        	int low = 0;
	int high = arr.size()-1;
	

	int mid;
	
	while(low <= high)
	{
		//int mid = (low+high)/2;
		mid = low + (high - low)/2;
		
		if(target == arr[mid])
		{
			return mid;
		}
		
		
			if(target > arr[mid])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		
		
	}

	return -1;
    }
};
-----------------
Solution with STL
class Solution {
public:
    int search(vector<int>& nums, int target) {
       auto it = std::lower_bound(nums.begin(),nums.end(),target); 
       if(it != nums.end() && *it == target)
            return std::distance(nums.begin(),it);
        return -1;
    }
};
	
