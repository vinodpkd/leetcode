#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> d;
        for(int i = 0; i < nums.size(); i++){
            if(d.count(target - nums[i])) 
				return {d[target - nums[i]], i};
            d[nums[i]] = i;
        }
}
int main()
{
	std::vector<int> nums {2, 7, 11, 15};
	int target = 26;
	
	std::vector<int> res = twoSum(nums, target);
	
	std::cout << res[0] << "," << res[1] << '\n';
	
	return 0;
	
}
