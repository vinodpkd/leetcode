//2535. Difference Between Element Sum and Digit Sum of an Array
/*
You are given a positive integer array nums.
The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.
Note that the absolute difference between two integers x and y is defined as |x - y|.
*/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int vsum{0};
        int dsum{0};
        for(int i = 0;i < nums.size();i++)
        {
            vsum += nums[i];
            if(nums[i] > 9)
                dsum += sum_digits(nums[i]);
            else
                dsum += nums[i];
        }

        return abs(vsum - dsum);
    }

    int sum_digits(int n)
    {
        int sum{0};

        while(n != 0)
        {
            int r = n % 10;

            sum += r;
            
            n = (n-r)/10;
        }

        return sum;
    }
};
