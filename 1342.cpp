//1342. Number of Steps to Reduce a Number to Zero
/*
Given an integer num, return the number of steps to reduce it to zero.
In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/
class Solution {
public:
    int numberOfSteps(int n) {
        int count = 0;
        while(n > 0)
        {
            if(n % 2 == 0)
            {
                n = n/2;
            }
            else
            {
                n--;
            }

            count++;
        }

        return count;
        
    }
};
