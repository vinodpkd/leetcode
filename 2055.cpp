//2055. Plates Between Candles
/*
There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.
You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.
For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.
*/
std::vector<int> pbc(std::string s, std::vector<std::vector<int>>& queries) {
	
        std::vector<int> res{};
        for(std::vector<int> q : queries)
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
    }
