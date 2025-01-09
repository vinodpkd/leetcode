//41. First Missing Positive
/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minm = 1;
        std::set<int> u{};
        for(int i = 0;i < nums.size();i++)
        {
            if(!u.contains(nums[i]) && nums[i] > 0)
            {
                u.insert(nums[i]);
            }
        }

        for(int x : u)
            std::cout << x << ' ';

        std::cout << '\n';

        if(!u.contains(1))
            return 1;
        else
        {
            auto it = u.begin();
            it++;
            while(it != u.end())
            {
                auto it2 = it;
                it2--;
                std::cout << *it2 << ' ' << *it << '\n';
                if(*it - *(it2) > 1)
                    return *it2+1;
                it++;
            }

            if(it == u.end())
                return *(it--)+1;
            
        }
        return 1;
    }
};
