//3. Longest Substring Without Repeating Characters
/*
Given a string s, find the length of the longest substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(0 == s.length())
            return 0;

         
        int maxlen = 1;
        int start = 0, end = 0;
        std::unordered_set<int> chars{};
        for(int i = 0;i < s.length();i++)
        {
            if(chars.count(s[i]) == 0)
            {
                chars.insert(s[i]);
            }
            else
            {
                end = i - 1;
                start = i - chars.size();
                maxlen = std::max(maxlen,end-start+1);
                auto it = std::find(s.begin()+start,s.begin()+i,s[i]);
                int d = std::distance(s.begin()+start,it);
                chars.clear();
                //std::copy(it,s.begin()+i,chars.begin());
                while(it < s.begin()+i)
                {
                    chars.insert(*it);
                    it++;
                }
            }
        }

        if(chars.size() == s.length())
            return s.length();
        return std::max(maxlen,(int)chars.size());
    }
};

-----------------
    Let me analyze the time and space complexity of this function step by step. The function appears to be finding the length of the longest substring without repeating characters.

Time Complexity Analysis:
1. The main loop iterates through the string once - O(n)
2. Inside the else branch, we have:
   - find() operation which scans from start to i - O(n) in worst case
   - distance() operation - O(1)
   - A while loop that can process up to i elements - O(n) in worst case
   - insert operations in unordered_set - O(1) average case
3. The operations in the else branch can be triggered O(n) times in worst case

Therefore, the overall time complexity is O(n²) in the worst case. This is because for each character (O(n)), we might need to perform find() and the while loop operations (both O(n)).

Space Complexity Analysis:
1. The unordered_set 'chars' stores unique characters - O(k) where k is the size of character set
   (k ≤ min(n, total possible characters in the character set))
2. Other variables (maxlen, start, end, i) use constant space - O(1)

Therefore, the overall space complexity is O(k), where k is the size of the character set.

Note that this implementation could be optimized to achieve O(n) time complexity by using a different approach, such as the sliding window technique with a hash map storing character positions.
-----------------
    Two pointers solution
// Array to store the last index
    // where each character occurred
    int hash[256];
    
    // Initialize all elements
    // of the array to -1
    fill_n(hash, 256, -1);
    
    // Get the length of
    // the input string
    int n = s.size();
    
    // Pointers to keep track
    // of the current substring
    int l = 0, r = 0;
    
    // Variable to store the maximum
    // length of substring without
    // repeating characters
    int maxLen = 0;
    
    // Loop until the right pointer
    // reaches the end of the string
    while (r < n) {
        // If the current character
        // has been seen before
        if (hash[s[r]] != -1) {
            // If its last occurrence is
            // within the current substring
            if (hash[s[r]] >= l) {
                // Move the left pointer to the
                // position after the last occurrence
                // of the current character
                l = hash[s[r]] + 1;
            }
        }
        
        // Calculate the length
        // of the current substring
        int len = r - l + 1;
        
        // Update the maximum
        // length if needed
        maxLen = max(len, maxLen);
        
        // Update the last occurrence
        // index of the current character
        hash[s[r]] = r;
        
        // Move the right pointer
        // to the next position
        r++;
    }
    // Return the maximum length of
    // substring without repeating characters
    return maxLen;
