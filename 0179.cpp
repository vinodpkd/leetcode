//179. Largest Number
/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::string s{};
        std::multiset<std::string,std::greater<std::string>> m{};
        for(int i = 0;i < nums.size();i++)
        {
            m.insert(std::to_string(nums[i]));
        }

        //std::multiset<char,std::greater<char>> m(s.begin(),s.end());
        std::string t{};
        for(auto x : m)
        {
            std::string u{x};
            t += u;
        }

        return t;
            
    }
};

// Convert integers to strings for easier comparison
        std::vector<std::string> numStr;
        for(int num : nums) {
            numStr.push_back(std::to_string(num));
        }
        
        // Custom comparator to sort strings based on concatenation
        sort(numStr.begin(), numStr.end(), [](std::string& a, std::string& b) {
            return a + b > b + a;
        });
        
        // Edge case: if all numbers are 0
        if(numStr[0] == "0") {
            return "0";
        }
        
        // Join all strings to form the result
        string result;
        for(std::string& str : numStr) {
            result += str;
        }
        
        return result;
    }
};
Let's break down how this solution works:

Convert to Strings:

First, we convert all integers to strings to make comparisons easier
This allows us to use string concatenation for comparison


Custom Sorting:

We sort the strings using a custom comparator
For any two numbers a and b, we compare their concatenations: a+b vs b+a
If a+b > b+a, then a should come before b
Example: For 3 and 30:

Compare "330" vs "303"
"330" > "303", so 3 comes before 30




Handle Edge Case:

If after sorting, the first number is "0", it means all numbers were zero
In this case, we return "0" instead of multiple zeros


Join Results:

Finally, we concatenate all strings to form the largest possible number



Example Usage:
cppCopyInput: nums = [10,2]
Output: "210"

Input: nums = [3,30,34,5,9]
Output: "9534330"
Time Complexity: O(nlogn * m) where n is the number of integers and m is the average length of strings
Space Complexity: O(n) for storing the strings
The key insight is that we need to compare numbers based on their concatenated results rather than their individual values. This ensures we get the largest possible number when combining the digits.
Would you like me to explain any specific part in more detail? CopyRetryClaude does not have the ability to run the code it generates yet.Claude can make mistakes. Please double-check responses.
