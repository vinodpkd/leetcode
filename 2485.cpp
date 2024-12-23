//2485. Find the Pivot Integer
/*
Given a positive integer n, find the pivot integer x such that:
    The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.
*/
class Solution {
public:
    int pivotInteger(int n) {
        if(1 == n)
            return 1;
        int gs = (n)*(n+1)/2;
        for(int i = 1;i < n;i++)
        {
            int ls = (i)*(i+1)/2;
            int rs = gs - ls + i;
            if(ls == rs)
                return i;
        }

        return -1;
    }
};
