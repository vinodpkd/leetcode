//2553. Separate the Digits in an Array
/*
Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.

To separate the digits of an integer is to get all the digits it has in the same order.

    For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].

  */
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        std::vector<int> all_digits{};
        for(int i = 0;i < nums.size();i++)
        {
            int n = nums[i];
            if(n < 10)
                all_digits.push_back(n);
            else
            {
                std::vector<int> digits{};
				while(n != 0)
				{
					int r = n % 10;
					digits.insert(digits.begin(),r);
					n = (n-r)/10;
				}
				//std::reverse(digits.begin(),digits.end());
				for(int j = 0;j < digits.size();j++)
					all_digits.push_back(digits[j]);
				}
            
        }

        return all_digits;
        
    }
};
