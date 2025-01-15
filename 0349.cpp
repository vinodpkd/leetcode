//349 Intersection of two arrays leetcode
#include <algorithm>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> setOne {},setTwo{};
        //std::set<int> setOne(nums1.begin(),nums1.end()),setTwo(nums2.begin(),nums2.end());
        int i = 0;
        while(i < nums1.size())
            {setOne.insert(nums1[i]);i++;}

        i = 0;
        while(i < nums2.size())
            {setTwo.insert(nums2[i]);i++;}
       
        std::vector<int> inter;
std::set_intersection(setOne.begin(),setOne.end(),setTwo.begin(),setTwo.end(), std::back_inserter(inter));
        return inter;
    }
};

-------
    //Two pointers solution 
    class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        std::ranges::sort(a);
        std::ranges::sort(b);
        std::vector<int> res{};
	
	int i = 0;
	int j = 0;
	
	while(i < a.size() && j < b.size())
	{
		if(a[i] > b[j])
		{
			j++;
            continue;			
		}
		
		if(a[i] == b[j])
		{if(res.empty())
				res.push_back(a[i]);
			else
			{
				if(res.back() != a[i])
					res.push_back(a[i]);
			}
			
			i++;
			j++;
			continue;			
		}
		
		if(a[i] < b[j])
		{
			i++;			
		}
	}

    return res;
    }
};
