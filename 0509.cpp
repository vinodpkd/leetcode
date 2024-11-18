#509. Fibonacci Number
class Solution {
public:
    int fib(int n) {
        if(n < 0)
            return 0;
        if(n == 0)
            return 0;
        if(1 == n)
            return 1;
        if(2 == n)
            return 1;
        return fib(n - 1) + fib(n-2);
    }
};
