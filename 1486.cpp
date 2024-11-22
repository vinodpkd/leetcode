//1486. XOR Operation in an Array
/*
You are given an integer n and an integer start.
Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.
Return the bitwise XOR of all elements of nums.
*/
class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        int count{1};
        //int i = start;
        while(count < n)
        {
           res = res ^ (start + count*2);
           count++;
        }
        return res;
    }
};
