//2195. Append K Integers With Minimal Sum
/*
You are given an integer array nums and an integer k. Append k unique positive integers that do not appear in nums to nums such that the resulting total sum is minimum.
Return the sum of the k integers appended to nums.
*/
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        std::ranges::sort(nums);
        int i = 1;
        long long int sum{0};
        std::vector<int> m{};
        int count{0};
        for(int j = 0;j < nums.size();j++)
        {
            for(int p = i;p < nums[j];p++)
            {
                count++;
                int last = p;
                sum += p;
                if(count == k)
                    return sum;
            }
            i = nums[j]+1;
        }
        //for(int x : m)
        //    std::cout << x << ' ';
        //std::cout << '\n';
        if(count < k)
        {
            for(int q = nums[nums.size()-1] + 1;q <= nums[nums.size()-1] + (k - count);q++)
                sum += q;
            return sum;
        }
            return nums[nums.size()-1] + (k - m.size());
        
        return 1;
    }
};
