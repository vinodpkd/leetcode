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

-----------------
//Two pointers
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Sort both arrays first for two pointer approach
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // Remove duplicates from both arrays
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        
        vector<int> diff1;  // Elements unique to nums1
        vector<int> diff2;  // Elements unique to nums2
        
        // Two pointers
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                // Current element in nums1 is smaller, so it's unique to nums1
                diff1.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                // Current element in nums2 is smaller, so it's unique to nums2
                diff2.push_back(nums2[j]);
                j++;
            }
            else {
                // Elements are equal, skip both
                i++;
                j++;
            }
        }
        
        // Add remaining elements from nums1
        while (i < nums1.size()) {
            diff1.push_back(nums1[i]);
            i++;
        }
        
        // Add remaining elements from nums2
        while (j < nums2.size()) {
            diff2.push_back(nums2[j]);
            j++;
        }
        
        return {diff1, diff2};
    }
};
