//3194. Minimum Average of Smallest and Largest Elements
/*
You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
You repeat the following procedure n / 2 times:
    Remove the smallest element, minElement, and the largest element maxElement, from nums.
Add (minElement + maxElement) / 2 to averages.
Return the minimum element in averages.
*/

class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        double avg{0.0};

        int size = nums.size();

        for(int i = 0;i < size/2;i++)
        {
            auto minm_it = std::min_element(nums.begin(),nums.end());
            int minm = *minm_it;
            nums.erase(minm_it);
            
            std::cout << "min " << minm << '\n';

            auto maxm_it = std::max_element(nums.begin(),nums.end());
            int maxm = *maxm_it;
            std::cout << "max " << maxm << '\n';
            nums.erase(maxm_it);
            double sumnow = ((double)(minm) + (double)(maxm))/2.0;
            std::cout << "sumnow " << sumnow << '\n';
            if(0 == i)
            {avg = sumnow;} 
            else
            {
                if(avg > sumnow)
                    avg = sumnow;
            }
            std::cout << "avg " << avg << "\n\n";
        }

        return avg;
    }
};
