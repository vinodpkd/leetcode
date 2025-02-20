//1980. Find Unique Binary String


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
         int n = nums[0].length();
        string result;
        
        // Use Cantor's diagonalization
        for (int i = 0; i < n; i++) {
            // Flip the bit at diagonal position
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        
        return result;
    }
};
