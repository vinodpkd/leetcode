//164. Maximum Gap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(1 == nums.size())
            return 0;
        std::set<int> setOne (nums.begin(),nums.end());
        if(1 == setOne.size())
            return 0;
        auto it = setOne.begin();
        int max = *it;
        std::advance(it,1);
        max = *it - max;
        auto end_1 = setOne.end();
        std::advance(end_1,-1);
        for(;it != end_1;it++)
        {
            auto itOne = it;
            int a = *it;
            std::advance(itOne,1);
            int b = *itOne;
            int diff = b-a;
            if(max < diff)
                max = diff;
        }
        return max;     
    }
};
