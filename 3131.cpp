//3131. Find the Integer Added to Array I
/*
You are given two arrays of equal length, nums1 and nums2.
Each element in nums1 has been increased (or decreased in the case of negative) by an integer, represented by the variable x.
As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.
Return the integer x.
*/
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        //std::sort(nums1.begin(),nums1.end());
        //std::sort(nums2.begin(),nums2.end());
        //return nums2[0] - nums1[0];
        int a = *std::min_element(nums2.begin(),nums2.end());
        int b = *std::min_element(nums1.begin(),nums1.end());
        return a - b;
    }
};
