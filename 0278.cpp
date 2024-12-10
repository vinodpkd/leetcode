//278. First Bad Version
/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Using long to prevent integer overflow
        long left = 1;
        long right = n;
        
        while (left < right) {
            // Prevent integer overflow by using (left + (right - left) / 2)
            long mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                // If current version is bad, it might be the first bad version
                // or the first bad version is before it
                right = mid;
            } else {
                // If current version is good, first bad version is after it
                left = mid + 1;
            }
        }
        
        // At this point, left == right and it's the first bad version
        return left;
    }
};
