//3248. Snake in Matrix
/*
There is a snake in an n x n matrix grid and can move in four possible directions. Each cell in the grid is identified by the position: grid[i][j] = (i * n) + j.
The snake starts at cell 0 and follows a sequence of commands.
You are given an integer n representing the size of the grid and an array of strings commands where each command[i] is either "UP", "RIGHT", "DOWN", and "LEFT". It's guaranteed that the snake will remain within the grid boundaries throughout its movement.
*/
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0,j = 0;
        for(std::string s : commands)
        {
            if("RIGHT" == s)
                {j++; continue;}
                
            if("DOWN" == s)
                {i++; continue;}
            if("UP" == s)
                {i--; continue;}
            if("LEFT" == s)
                {j--; continue;}
        }

        return i*n + j;
    }
};
