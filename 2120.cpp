//2120. Execution of All Suffix Instructions Staying in a Grid
/*
There is an n x n grid, with the top-left cell at (0, 0) and the bottom-right cell at (n - 1, n - 1). You are given the integer n and an integer array startPos where startPos = [startrow, startcol] indicates that a robot is initially at cell (startrow, startcol).
You are also given a 0-indexed string s of length m where s[i] is the ith instruction for the robot: 'L' (move left), 'R' (move right), 'U' (move up), and 'D' (move down).
The robot can begin executing from any ith instruction in s. It executes the instructions one by one towards the end of s but it stops if either of these conditions is met:

  The next instruction will move the robot off the grid.
  There are no more instructions left to execute.
Return an array answer of length m where answer[i] is the number of instructions the robot can execute if the robot begins executing from the ith instruction in s.
*/
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        std::vector<int> res(s.size());
	for(int i = 0;i < s.size();i++)
	{
		int p = startPos[0],q = startPos[1];
		int count{0};
		bool stop = false;
		
		for(int j = i;j < s.size();j++)
		{
			
			if('L' == s[j])
			{
				
				q--;                    
				if(q < 0)
				{
					stop = true;
				}
				else
				{
					count++;
				}
			}

			if('R' == s[j])
			{
				
				q++;                    
				if(q > (n-1))
				{
					stop = true;
				}
				else
				{
					count++;
				}
			}

			if('U' == s[j])
			{
				
				p--;                    
				if(p < 0)
				{
					stop = true;
				}
				else
				{
					count++;
				}
			}
			
			if('D' == s[j])
			{
				
				p++;                    
				if(p > (n-1))
				{
					stop = true;
				}
				else
				{
					count++;
				}
			}
			
			//std::cout << "i = " << i << " j = " << j << " s[j] = " << s[j] << " count = " << count << '\n';

			if(true == stop)
			{
				//std::cout << "(true == stop) i = " << i << " j = " << j << " s[j] = " << s[j] << " count = " << count << "\n\n";
				//res[i] = count;
				break;    
			}
			
			
		}
		
		res[i] = count;

	}

	return res;
    }
};
