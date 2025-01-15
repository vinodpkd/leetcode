//350. Intersection of Two Arrays II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> msetOne (nums1.begin(), nums1.end());
        multiset<int> msetTwo (nums2.begin(), nums2.end());
        std::vector<int> inter;
		std::set_intersection(msetOne.begin(),msetOne.end(),msetTwo.begin(),msetTwo.end(), std::back_inserter(inter));
        return inter;
    }
};

--------
//Two pointers approach
class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
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
		{
			
					res.push_back(a[i]);
			
			
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
