//1652. Defuse the Bomb
/*
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

    If k > 0, replace the ith number with the sum of the next k numbers.
    If k < 0, replace the ith number with the sum of the previous k numbers.
    If k == 0, replace the ith number with 0.

As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        std::vector<int> res(code.size(),0);
        if(0 == k)
            return res;
        
        int size = code.size();

        if(k > 0)
        {
            for(int i = 0;i < code.size();i++)
            {
                int sum{0};
                for(int j = i+1;j < i+1+k;j++)
                {
                    
                    int p = j % size;                 

                    sum += code[p];

                }

                res[i] = sum;   
            }
        }
        else
        {
            for(int i = 0;i < size;i++)
            {
                int sum{0};
				int j = i-1;
                for(int q = 0;q < abs(k);q++)
                {
                    int p = (j + size) % size;
                    sum += code[p];
					//std::cout << "i = " << i << " j = " << j << " p = " << p << " code[p] = " << code[p] << " sum = " << sum << '\n';
					j--;
                }
                res[i] = sum; 
            }
            
        }
        
        return res;
    }
};
