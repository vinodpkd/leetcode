//219. Contains Duplicate II
//Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
#include <bits/stdc++.h>

bool containsNearbyDuplicate(std::vector<int>& nums, int r) {
        
	if(nums.empty())
		return false;

	std::multiset<int> mset(nums.begin(),nums.end());
	std::set<int> setOne(nums.begin(),nums.end());
	std::vector<int> vec{};

	for(auto it = setOne.begin();it != setOne.end();it++)
	{
		if(mset.count(*it) > 1)
			vec.push_back(*it);
	}

	//for(auto& x : vec)
	//	std::cout << x << '\n';

	if(vec.empty())
		return false;

	std::map<int,std::vector<int>> omap{};

	for(size_t i = 0;i < vec.size();i++)
	{
		for(size_t j = 0;j < nums.size();j++)
		{
			if(vec[i] == nums[j])
			{
				/*
				bool flagOne = false,flagTwo = false;
				if(omap[vec[i]].size() > 2)
				{
					for(int q = 0;q <  omap[vec[i]].size();q++)
					{
						if(omap[vec[i]][q] == i)
							flagOne == true;
						if(omap[vec[i]][q] == j)
							flagTwo == true;
					}
				}
				
				if(false == flagOne)
					{omap[vec[i]].push_back(i);}
				
				if(false == flagTwo)
					{omap[vec[i]].push_back(j);}
				
				std::cout << vec[i] << ',' << nums[j] << '\n';
				*/
				
				omap[vec[i]].push_back(j);
				
				if(1 < omap[vec[i]].size())
				{
					//std::cout << "if(1 < omap[vec[i]].size()) " << omap[vec[i]][0] << ',' << omap[vec[i]][1] << '\n';
					
					for(int k = 0;k <  omap[vec[i]].size();k++)
					{
						for(int p = k+1;p <  omap[vec[i]].size();p++)
						{
							//std::cout << "for(int p = k+1;p <  omap[vec[i]].size();p++) " << omap[vec[i]][k] << ',' << omap[vec[i]][p] << '\n';
							if(abs(omap[vec[i]][k] - omap[vec[i]][p]) <= r)
								 {return true;}
						}
					}
				}
			}
		}
	}

	return false;
}

int main()
{
	//std::vector<int> nums{-1,-1};
	//std::vector<int> nums{1,2,3,1};
	std::vector<int> nums{1,2,3,1,2,3};
	int k = 2;
	
	bool a = containsNearbyDuplicate(nums,k);
	
	std::cout << a << '\n';
	
	return 0;
	
}
