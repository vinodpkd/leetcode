//2574. Left and Right Sum Differences
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        std::vector<int> lrsum{};

        int lsum{0},rsum{0};

        for(int i = 0; i < nums.size();i++)
        {
            if(i > 0)
                lsum = std::accumulate(nums.begin(),nums.begin() + i,0);
            else
                lsum = 0;

            //std::cout << "i = " << i << " lsum = " << lsum << '\n';

            if(i == (nums.size() - 1))
                rsum = 0;
            else    
                rsum = std::accumulate(nums.begin()+i+1,nums.end(),0);

            //std::cout << "i = " << i << " rsum = " << rsum << '\n';

            lrsum.push_back(abs(lsum - rsum));
        }

        return lrsum;
    }
};
