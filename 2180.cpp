//2180. Count Integers With Even Digit Sum
/*
Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.
The digit sum of a positive integer is the sum of all its digits.
*/

class Solution {
public:
    int countEven(int num) {
        int count{0};
		
        for(int i = 1;i <= num;i++)
        {
            int n = i;
            if(n < 10)
			{
				if(n%2 == 0)
					count++;
			}
            else
            {
                int dsum{0};
				
				while(n != 0)
				{
					int r = n % 10;
					dsum += r;
					n = (n-r)/10;
				}
				
				if(dsum % 2 == 0)
					count++;
            }
        }

        return count;
    }
};
