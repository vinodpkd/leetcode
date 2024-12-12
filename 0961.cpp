//961. N-Repeated Element in Size 2N Array
/*
You are given an integer array nums with the following properties:
    nums.length == 2 * n.
    nums contains n + 1 unique elements.
    Exactly one element of nums is repeated n times.
Return the element that is repeated n times.
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int c{0};
        for(int i = 0;i < nums.size()/2 + 1;i++)
        {
            int n = nums[i];
            c = std::count_if(nums.begin(),nums.end(),[n](int m){return m == n;});
            if(c == nums.size()/2)
                return n;
        }
        return c;
    }
};
