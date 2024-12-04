//2215. Find the Difference of Two Arrays
/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
    answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
    answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dist{};
        std::set<int> set1(nums1.begin(),nums1.end());
        std::set<int> set2(nums2.begin(),nums2.end());
        std::vector<int> answer0{};
        std::set_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),std::back_inserter(answer0));
        std::vector<int> answer1{};
        std::set_difference(set2.begin(),set2.end(),set1.begin(),set1.end(),std::back_inserter(answer1));
        dist.push_back(answer0);
        dist.push_back(answer1);
        return dist;
    }
};
