//69. Sqrt(x)
class Solution {
public:
    int mySqrt(int num) {

        long long int num1 = num;

        if(0 == num1 || 1 == num1)
		return num1;

    /*if(4 > num1)
		return 1;
	
	if(5 == num1 || 6 == num1 || 7 == num1)
		return 2;
    */
	int low = 0;
	int high = num1 - 1;
	
	//std::cout << "Low = " << low << " High = " << high << '\n';
	
	long long int mid;
	
	while(low <= high)
	{
		
		mid = low + (high - low)/2;
		
		//std::cout << "Start of while loop : \n mid = " << mid << '\n';
		
		if(num1 == mid*mid)
		{
			return mid;
		}
		
		
		if(num1 > mid*mid)
		{
			if(num1 < (mid+1)*(mid+1))
                return mid;
            else
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
	return mid;
    }
};
