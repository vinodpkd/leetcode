//728. Self Dividing Numbers
/*
A self-dividing number is a number that is divisible by every digit it contains.

    For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).
*/
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        std::vector<int> res{};
        for(int i = left;i <= right;i++)
        {
            if(self_divide(i))
                res.push_back(i);
        }
        return res;
        
    }

    bool self_divide(int n)
    {
        int m = n;

        while(n != 0)
        {
            int r = n % 10;
            if(0 == r)
            {
                return false;
            }
            if(m % r != 0)
                return false;
            n = (n-r)/10;

        }
        return true;
    }
};
