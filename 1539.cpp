//1539. Kth Missing Positive Number
/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.
*/
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int i = 1;
        std::vector<int> m{};
        for(int j = 0;j < nums.size();j++)
        {
            for(int p = i;p < nums[j];p++)
            {
                m.push_back(p);
                if(m.size() == k)
                    return p;
            }
            i = nums[j]+1;
        }
        //for(int x : m)
        //    std::cout << x << ' ';
        //std::cout << '\n';
        if(m.size() < k)
            return nums[nums.size()-1] + (k - m.size());
        
        return 1;
    }
};
