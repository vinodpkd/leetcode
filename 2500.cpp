//2500. Delete Greatest Value in Each Row
/*
You are given an m x n matrix grid consisting of positive integers.
Perform the following operation until grid becomes empty:
    Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
    Add the maximum of deleted elements to the answer.
Note that the number of columns decreases by one after each operation.
Return the answer after performing the operations described above.
*/
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int c{0};
		
		
		
		while(grid[0].size() >= 1)
		{
			std::vector<int> res{};
			
			for(int i = 0;i < grid.size();i++)
			{
				auto it = std::max_element(grid[i].begin(),grid[i].end());
				res.push_back(*it);
				grid[i].erase(it);
				//print(grid[i]);
			}
			
			//print(res);
			
			c = c + *std::max_element(res.begin(),res.end());
		}
		
		//std::cout << " c = " << c << '\n';
		return c;
    }
};
