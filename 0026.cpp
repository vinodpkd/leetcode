//26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int start,end;
        while(i < nums.size())
        {
            start = i,end = 0;
            if((i+1) < nums.size() && nums[i] == nums[i+1])
            {
                
                i++;
                while((i+1) < nums.size() && nums[i] == nums[i+1])
                {i++;}
                end = i;
                nums.erase(nums.begin()+start,nums.begin()+end);
                i = i - (end - start);
            }
            else
            {
                i++;
            }

            
        }

        return nums.size();
    }
};
