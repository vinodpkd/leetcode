//2778. Sum of Squares of Special Elements
/*
You are given a 1-indexed integer array nums of length n.
An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.
Return the sum of the squares of all special elements of nums.
*/
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sumsq{0};
        int size = nums.size();
        for(int i = 1;i <= size;i++)
        {
            if(size % i == 0)
            {
                sumsq += nums[i-1]*nums[i-1];
            }
        }

        return sumsq;
    }
};
