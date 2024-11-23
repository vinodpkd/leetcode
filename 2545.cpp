//2545. Sort the Students by Their Kth Score
/*
There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.
You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.
Return the matrix after sorting it.
*/
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        for(int j = 0;j < score.size()-1;j++)
	{
		for(int i = 0;i < score.size()-1;i++)
		{
			if(score[i][k] < score[i+1][k])
				std::swap(score[i],score[i+1]);
		}
	}
    
	return score;  
    }
};
