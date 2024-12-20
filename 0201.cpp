//201. Bitwise AND of Numbers Range,Incomplete
/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
left =
1073741824
right =
2147483647
Time Limit Exceeded
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right)
            return left;
        int res = left & left + 1;

        if(right == left+1)
            return res;

        if(res == 0)
            return 0;
        
        for(int i = left + 2;i <= right;i++)
        {
            res = res & i;
            if(res == 0)
                return 0;
        }

        return res;
    }
};
