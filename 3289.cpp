//3289. The Two Sneaky Numbers of Digitville
/*In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, 
two mischievous numbers sneaked in an additional time, making the list longer than usual.
As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.
*/
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        std::multiset<int> msetOne (nums.begin(), nums.end());
        std::set<int> setTwo (nums.begin(), nums.end());
        std::vector<int> diff;
		std::set_difference(msetOne.begin(),msetOne.end(),setTwo.begin(),setTwo.end(), std::back_inserter(diff));

        return diff;
        
		
    }
};
