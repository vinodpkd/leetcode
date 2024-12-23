//633. Sum of Square Numbers
/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(0 == c)
            return true;
        long int i = 0;
        while(i*i < c)
        {
            int j = c - i*i;
            if(isPerfectSquare(j))
                return true;
            i++;
        }

        return false;
    }

    bool isPerfectSquare(int num) {
        if(0 == num || 1 == num)
		return true;

    /*if(4 > num1)
		return 1;
	
	if(5 == num1 || 6 == num1 || 7 == num1)
		return 2;*/

	int low = 0;
	int high = 46340;
	
	//std::cout << "Low = " << low << " High = " << high << '\n';
	
	int mid;
	
	while(low <= high)
	{
		
		mid = low + (high - low)/2;
		
		//std::cout << "Start of while loop : \n mid = " << mid << '\n';
		
		if(num == mid*mid)
		{
			return true;
		}
		
		
		if(num > mid*mid)
		{			
                low = mid + 1;
			//std::cout << "low = " << low << '\n';
		}
		else
		{
			high = mid - 1;
			//std::cout << "high = " << high << '\n';
		}		
		
		//std::cout << "end of while loop\n";
	}

	//return low;	
	return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        
        while (left <= right) {
            long long sum = left * left + right * right;
            if (sum == c) return true;
            if (sum < c) left++;
            else right--;
        }
        return false;
    }
};

