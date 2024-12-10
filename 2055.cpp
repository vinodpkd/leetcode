//2055. Plates Between Candles
/*
There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.
You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.
For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.
*/
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {

        int n = s.length();
        
        // Store indices of candles
        vector<int> candleIndices;
        
        // Prefix sum of plates
        vector<int> platePrefix(n + 1, 0);
        
        // Populate candle indices and plate prefix sum
        for (int i = 0; i < n; i++) {
            // Track plate prefix sum
            platePrefix[i + 1] = platePrefix[i] + (s[i] == '*' ? 1 : 0);
            
            // Track candle indices
            if (s[i] == '|') {
                candleIndices.push_back(i);
            }
        }
        
        // Result vector to store answers for each query
        vector<int> result;
        
        // Process each query
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            // Find the first candle index >= left
            auto leftCandle = lower_bound(candleIndices.begin(), candleIndices.end(), left);
            
            // Find the last candle index <= right
            auto rightCandle = upper_bound(candleIndices.begin(), candleIndices.end(), right);
            
            // If not enough candles, add 0 to result
            if (leftCandle == candleIndices.end() || 
                rightCandle == candleIndices.begin() || 
                *leftCandle > right || 
                *(rightCandle - 1) < left) {
                result.push_back(0);
                continue;
            }
            
            // Move to last candle to the left of right
            rightCandle--;
            
            // Calculate plates between the leftmost and rightmost candles
            int plates = platePrefix[*rightCandle + 1] - platePrefix[*leftCandle];
            
            result.push_back(max(0, plates));
        }
        
        return result;
        
        /*
        std::vector<int> res{};
        for(vector<int> q : queries)
        {
            std::string sub = s.substr(q[0],q[1]+1);
            int f = sub.find('|');
            int l = sub.rfind('|');
            std::cout << sub << ' ' << f << ' ' << l << '\n';
            if(f < l)
            {
                int count = std::count(sub.begin()+f,sub.begin()+l+1,'*');
                std::cout<< count << "\n\n";
                res.push_back(count);
            }
            else
            {
                res.push_back(0);
            }
        }

        return res;
        */
    }
};
