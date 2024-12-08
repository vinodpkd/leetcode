//2917. Find the K-or of an Array
/*
You are given an integer array nums, and an integer k. Let's introduce K-or operation by extending the standard bitwise OR. In K-or, a bit position in the result is set to 1 if at least k numbers in nums have a 1 in that position.
Return the K-or of nums.
*/
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        std::vector<int> nb(32,0);
	
	for(int i = 0;i < nums.size();i++)
	{
		std::bitset<32> x(nums[i]);
		for(int i = 0;i < nb.size();i++)
		{
			if(x[i])
				nb[i]++;
		}
	}
	
	//print(nb);
	
	int res{0};
	
	for(int i = 0;i < nb.size();i++)
	{
		if(nb[i] >= k)
			res += std::pow(2,i);

	}
	
	return res;
    }
};
