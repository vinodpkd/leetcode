//88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        multiset<int> msetOne (nums1.begin(), nums1.begin() + m);
        multiset<int> msetTwo (nums2.begin(), nums2.begin() + n);
        msetOne.merge(msetTwo);
        nums1.clear();
        std::copy(msetOne.begin(), msetOne.end(), std::back_inserter(nums1));
    }
};
