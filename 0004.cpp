//Median of two sorted arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // std::vector<int> nums1 {0,5,9};
	//std::vector<int> nums2 {1,10,11};
	
	std::multiset<int> mset1 (nums1.begin(),nums1.end());
	
	std::multiset<int> mset2 (nums2.begin(),nums2.end());
	
	mset1.merge(mset2);
	//std::copy(nums1.begin(),nums1.end(),mset.begin());
	
	// for(auto& x : mset1)
		// std::cout << x << '\n';
	
	// std::cout << '\n';
	
	auto it = mset1.begin();
	
	int len = mset1.size();
	
	if(len % 2 != 0)
	{
		std::advance(it,len/2);
		//std::cout << *it << '\n';
        return *it;
	}
	else
	{
		auto it2 = mset1.begin();
		std::advance(it,len/2);
		std::advance(it2,len/2-1);
		//std::cout << (*it + *it2)/2.0 << '\n';
		return (*it + *it2)/2.0;
	}
        
    }
};
