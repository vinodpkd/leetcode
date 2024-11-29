//3300. Minimum Element After Replacement With Digit Sum
/*
You are given an integer array nums.
You replace each element in nums with the sum of its digits.
Return the minimum element in nums after all replacements.
  */
class Solution {
public:
    int minElement(vector<int>& nums) {
        int min = digits_sum(nums[0]);
        for(int i = 1;i < nums.size();i++)
        {
            int dsum = digits_sum(nums[i]);
            if (dsum < min)
                min = dsum;
        }
        return min;
    }

    int digits_sum(int n)
    {
        int sum{0};
        while (n != 0)
        {
            int r = n % 10;
            sum += r;
            n = (n-r)/10;
        }
        return sum;
    }
};
