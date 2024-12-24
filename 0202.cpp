//202. Happy Number
/*
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
*/
class Solution {
public:
    bool isHappy(int n) {
        if(1 == n)
            return true;
        //if(9 >= n)
            //return false;

        //int p = sumsqdigits(n);

        //std::cout << p << '\n';

        std::unordered_set<int> u{};

        while(true)
        {
            int p = sumsqdigits(n);

            
            if(1 == p)
                return true;

            if(u.count(p) != 0)
                return false;
            
            u.insert(p);
            n = p;
        }
        
        return false;
    }

    int sumsqdigits(int m)
    {
        
        int s{0};
        while(m != 0)
        {
            int r = m % 10;
            s = s + r*r;
            m = (m-r)/10;
        }

        return s;
    }
};
