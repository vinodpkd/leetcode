//560. Subarray Sum Equals K , Brute force
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count{0};
	
	for(int i = 0;i < arr.size();i++)
	{
        int sum = arr[i];
		for(int j = i;j < arr.size();j++)
		{
			//int sum = std::accumulate(arr.begin()+i,arr.begin()+j+1,0);
			if(sum == k)
			{
				count++;
			}
            if(j+1 == arr.size())
                break;
            sum += arr[j+1];
		}
	}
    return count;
    }
};
