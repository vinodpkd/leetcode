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
