//710. Random Pick with Blacklist
/*
You are given an integer n and an array of unique integers blacklist. Design an algorithm to pick a random integer in the range [0, n - 1] that is not in blacklist. Any integer that is in the mentioned range and not in blacklist should be equally likely to be returned.

Optimize your algorithm such that it minimizes the number of calls to the built-in random function of your language.

Implement the Solution class:

Solution(int n, int[] blacklist) Initializes the object with the integer n and the blacklisted integers blacklist.
int pick() Returns a random integer in the range [0, n - 1] and not in blacklist.
*/

class Solution {
    private:
    int n;
    vector<int> blacklist;
    std::vector<int> d{};
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,m-1); 
public:
    Solution(int n, vector<int>& blacklist):n(n),blacklist(blacklist) {
        
        std::vector<int> v(n);
        std::ranges::iota(v,0);
        std::set<int> s1(v.begin(),v.end());
        //std::vector<int> d{};
        if(0 != blacklist.size())
        {
        std::set<int> s2(blacklist.begin(),blacklist.end());
        
        std::ranges::set_difference(s1,s2,std::back_inserter(d));
        }
        else
        {
          d = v;
        }
        
        //for(auto x : d)
        //    std::cout << x << '\n';
        int m = d.size();
         std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,m-1); // distribution in range [1, 6]
    //std::cout << dist(rng) << '\n';
    
    }
    
    int pick() {
        
    return d[dist(rng)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
-----------------
    class Solution {
private:
    int n;
    unordered_map<int, int> mapping;
    int validRange;
    
public:
    Solution(int n, vector<int>& blacklist) {
        this->n = n;
        this->validRange = n - blacklist.size();
        
        // Create set of blacklisted numbers
        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());
        
        // Find valid numbers after validRange
        int validNum = validRange;
        for (int blackNum : blacklist) {
            // If blacklisted number is in our valid range
            if (blackNum < validRange) {
                // Find next valid number to map to
                while (blackSet.count(validNum)) {
                    validNum++;
                }
                mapping[blackNum] = validNum++;
            }
        }
    }
    
    int pick() {
        // Generate random number in valid range
        int randNum = rand() % validRange;
        
        // If this number was blacklisted, return its mapping
        // Otherwise return the number itself
        return mapping.count(randNum) ? mapping[randNum] : randNum;
    }
};
