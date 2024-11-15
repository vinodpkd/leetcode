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
