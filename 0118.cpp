//118. Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p {};
        for(int i = 1; i <= numRows;i++)
        {        
            vector<int> vec;

            if(1 == i)
            {
                 vec = {1}; 
            }
            else if(2 == i)
            {
                vec = {1,1}; 
            }
            else
            {
                

                for(int j = 0;j < i;j++)
                {
                    vec.push_back(choose(i-1,j));
                }
                
            }

            p.push_back(vec);

            
        }

        return p;
    }

    int choose(int n, int k)
    {
        if (k == 0)
            return 1;
        return (n * choose(n - 1, k - 1)) / k;
    }
};
