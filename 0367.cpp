#367. Valid Perfect Square
class Solution {
public:
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
