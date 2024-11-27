//2520. Count the Digits That Divide a Number
/*
Given an integer num, return the number of digits in num that divide num.
An integer val divides nums if nums % val == 0.
*/
class Solution {
public:
    int countDigits(int num) {

        if (num < 10)
            return 1;

        int n = num;
        
        std::multiset<int> s{};

        while(n != 0)
        {
            int d = n % 10;
            if(num % d == 0)
                s.insert(d);
            n = (n - d)/10;
        }

        return s.size();
        
    }
};
