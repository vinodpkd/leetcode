//2769. Find the Maximum Achievable Number
/*
Given two integers, num and t. A number is achievable if it can become equal to num after applying the following operation:
Increase or decrease the number by 1, and simultaneously increase or decrease num by 1.
Return the maximum achievable number after applying the operation at most t times.
*/
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + t*2;
        
    }
};
