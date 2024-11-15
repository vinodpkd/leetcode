//1574. Shortest Subarray to be Removed to Make Array Sorted,not completed
//[2,2,2,1,1,1] to be checked
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        auto it = std::is_sorted_until(arr.begin(),arr.end());	
	
	auto itDesc = std::is_sorted_until(arr.begin(),arr.end(),std::greater<>());	
	
	if(arr.end() != itDesc)
	{
		if(arr.end() != it)
		{
			std::vector<int>::iterator itOne,itTwo;
			
			//std::cout << "if arr.end() != it " << std::distance(arr.begin(),it) << '\n';
			
			itOne = std::is_sorted_until(it,arr.end(),std::greater<>());
			
			if(arr.end() != itOne)
			{
				itTwo = std::is_sorted_until(itOne,arr.end());
				
				//std::cout << "if arr.end() != itOne " << std::distance(it,itOne) + 1 << '\n';
				
				return std::distance(it,itOne) + 1;			
				
			}
			else
			{
				//std::cout << "else arr.end() != itOne " << std::distance(itOne,arr.end()) << '\n';
				return std::distance(itOne,arr.end());
			}
		
		}
		else
		{
			//std::cout << "else arr.end() != it\n"; 
			//std::cout << 0 << '\n';
			return 0;
		}
		
	}
	else
	{
		//std::cout << "else arr.end() != itDesc\n";
		//std::cout << arr.size() - 1 << '\n';
		return arr.size() - 1;
	}
	
	return 0;
    }
};
