//119. Pascal's Triangle II
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;

            if(0 == rowIndex)
            {
                 vec = {1}; 
            }
            else if(1 == rowIndex)
            {
                vec = {1,1}; 
            }
            else
            {
                
                for(int j = 0;j <= rowIndex;j++)
                {
                    vec.push_back(choose(rowIndex,j));
                }
                
            }    
        return vec;
    }

    int choose(int n, int k)
    {
        if (k == 0)
            return 1;
        return (n * choose(n - 1, k - 1)) / k;
    }
};
