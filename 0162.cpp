#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> arr {1,2,3,1};
	
	auto it = std::is_sorted_until(arr.begin(),arr.end());
	
	size_t index = std::distance(arr.begin(), it) - 1;

    std::cout << "Index of the peak element: " << index << std::endl; 
	
	std::cout << *it << std::endl; 

	return 0;
}
