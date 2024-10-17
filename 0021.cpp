#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int>& first,const std::vector<int>& second)
{
	size_t total_size = first.size() + second.size();
	
	if(first.size() == 0)
		return second;
	if(second.size() == 0)
		return first;
	
	std::vector<int> combined(first.size() + second.size());
	
	size_t count_first = 0;
	size_t count_second = 0;
	
	size_t count_combined = 0;
	
	while((count_first < first.size()) && (count_second < second.size()))	
	{
		std::cout << "In while loop\n";
		
		std::cout << "When comparing \n";
		
		std::cout << "first count = " << count_first << '\n';
		std::cout << "second count = " << count_second << '\n';
		
		std::cout << " first[count_first] " << first[count_first] << '\n';
		std::cout << " second[count_second] " << second[count_second] << '\n';		
		
		if(first[count_first] == second[count_second])
		{
			combined[count_combined++] = first[count_first];
			combined[count_combined++] = first[count_first];
			count_second++;
			count_first++;
		}
		else if(first[count_first] > second[count_second])
		{
			combined[count_combined++] = second[count_second];
			count_second++;
		}
		else
		{
			combined[count_combined++] = first[count_first];
			count_first++;
		}
		
		
		std::cout << "count = " << count_combined << '\n';
		std::cout << "first count = " << count_first << '\n';
		std::cout << "second count = " << count_second << '\n';
		
		for(int i = 0;i < count_combined;i++)
			std::cout << combined[i] << '\n';
		
		std::cout << "End while loop\n";
		
	}
	
	if(count_first == first.size())
		std::copy(second.begin()+count_first,second.end(),combined.begin() + count_combined);
	
	if(count_second == second.size())
		std::copy(first.begin()+count_second,first.end(),combined.begin() + count_combined);
	
	
	return combined;
		
	
	
}


int main()
{
	std::vector<int> one {-10,9,10,11,100};
	std::vector<int> two {-5,-1,0,10,100,200,205};
	
	std::vector<int> combined = merge(one,two);
	
	for(int& x : combined)
		std::cout << x << '\n';
	
	return 0;
}                                                                  
