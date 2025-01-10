//922. Sort Array By Parity II
/*
Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
Return any answer array that satisfies this condition.
*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& arr) {
        int i = 0;
	int j = 1;
	
	while(i < arr.size() && j < arr.size())
	{
		while(i < arr.size() && arr[i] % 2 == 0 && i % 2 == 0)
			i = i + 2;
		while(j < arr.size() && arr[j] % 2 == 1 && j % 2 == 1)
			j = j + 2;
		
		if(i > arr.size()-1 || j > arr.size()-1)
			break;
		
		std::cout << i << ' ' << j << ' ' << arr[i] << ' ' << arr[j] << '\n';
		
		
		std::swap(arr[i],arr[j]);
	}
    return arr;
    }
};
