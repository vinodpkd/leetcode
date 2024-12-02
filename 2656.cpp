//2656. Maximum Sum With Exactly K Elements
/*
You are given a 0-indexed integer array nums and an integer k. Your task is to perform the following operation exactly k times in order to maximize your score:
    Select an element m from nums.
    Remove the selected element m from the array.
    Add a new element with a value of m + 1 to the array.
    Increase your score by m.
Return the maximum score you can achieve after performing the operation exactly k times.
*/
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = *std::max_element(nums.begin(),nums.end());
        //std::set<int> s(nums.begin(),nums.end());
        //int i{0};
        //for(auto it = s.rbegin()+1;it != s.rend();it++)
        //{
            //max = max + *it
            //i++;
            //if(i == (k-1))
                //break;
        //}
        int max1 = 0;
        max--;
        for(int i = 0;i < k;i++)
        {
            max++;
            max1 = max1 + max;
            //std::cout << "max1 = " << max << " max = " << max << '\n';
        }
            
        return max1;
        
    }
};
