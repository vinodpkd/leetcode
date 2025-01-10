//905. Sort Array By Parity
/*
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition. 
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int i = 0;
	int j = arr.size()-1;
	
	while(i < j)
	{
		while(i < arr.size() && arr[i] % 2 == 0)
			i++;
		while(j >= 0 && arr[j] % 2 == 1)
			j--;
		
	if(i == arr.size() || j == -1)
		break;
		
		std::cout << i << ' ' << j << ' ' << arr[i] << ' ' << arr[j] << '\n';
		if(i < j)
			std::swap(arr[i],arr[j]);
	}
    return arr;
    }
};
