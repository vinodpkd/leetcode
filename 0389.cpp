//389. Find the Difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        std::multiset<int> msetOne (s.begin(), s.end());
        std::multiset<int> msetTwo (t.begin(), t.end());
        std::vector<int> diff;
		std::set_difference(msetTwo.begin(),msetTwo.end(),msetOne.begin(),msetOne.end(), std::back_inserter(diff));
        
		
		return diff[0];
    }
};
