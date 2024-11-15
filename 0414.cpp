//414. Third Maximum Number
class Solution {
public:
    int thirdMax(vector<int>& nums) {

        //auto comp = [](int a,int b){return a > b;};
        std::set<int,std::greater<int> > set1(nums.begin(),nums.end());
        //std::sort(set1.begin(),set1.end(),std::greater<>());
        if(set1.size() > 2)
            return *std::next(set1.begin(), 2);
        else
            return *std::next(set1.begin(), 0);
    }
};
