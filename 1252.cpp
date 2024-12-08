//1252. Cells with Odd Values in a Matrix
/*
There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to perform some increment operations on the matrix.
For each location indices[i], do both of the following:
    Increment all the cells on row ri.
    Increment all the cells on column ci.
Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.
*/
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        std::vector<std::vector<int>> c{};
        std::vector<int> row(n,0);
        for(int j = 0;j < m;j++)
        { 
            c.push_back(row);
			//print(c[j]);
        }
		

		
        for(std::vector<int> cd : indices)		
        {
			//print(cd);
            //std::transform(c[cd[0]].begin(),c[cd[0]].end(),c[cd[0]].begin(),[](int n){return n+1;});
			for(int j = 0;j < n;j++)
            {
                c[cd[0]][j]++;
            }
			//print(c[0]);
			//print(c[1]);
			//std::cout << '\n';
            for(int i = 0;i < m;i++)
            {
                c[i][cd[1]]++;
            }
			//print(c[0]);
			//print(c[1]);
			//std::cout << '\n';
        }
		
		int count{0};
		//std::cout << count << '\n';
        
        for(int i = 0;i < m;i++)
        {
            int cnow = std::count_if(c[i].begin(),c[i].end(),[](int n){return (n % 2 != 0);});
            count += cnow;
        }

		//std::cout << count << '\n';
		
        return count;	
    }
};
