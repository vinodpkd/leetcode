//2011. Final Value of Variable After Performing Operations
/*
  There is a programming language with only four operations and one variable X:
    ++X and X++ increments the value of the variable X by 1.
    --X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.
  */
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        //"--X","X++","X++","X--"
        for(int i = 0;i < operations.size();i++)
        {
            if("--X" == operations[i] || "X--" == operations[i])
                X = X - 1;

            if("++X" == operations[i] || "X++" == operations[i])
                X = X + 1;
        }

        return X;
    }
};
