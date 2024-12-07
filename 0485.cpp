//485. Max Consecutive Ones
/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& s) {
        if (s.size() == 1) {
            if (s[0] == 1)
                return 1;
            return 0;
        }
        int exist = std::count_if(s.begin(),s.end(),[](int n){ return n == 1;});
        if(0 == exist)
            return 0;
        int max{1};
        int i = 0;
        while (i < s.size()) {
            if ((i + 1) < s.size() && s[i] == 1 && s[i + 1] == 1) {
                i++;
                int count = 2;
                while ((i + 1) < s.size() && s[i] == 1 && s[i + 1] == 1) {
                    count++;
                    i++;
                }
                if (max < count)
                    max = count;
            } else {
                i++;
            }
        }

        return max;
    }
};
