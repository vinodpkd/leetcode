//2652. Sum Multiples
/*
Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.
Return an integer denoting the sum of all numbers in the given range satisfying the constraint.
*/
class Solution {
public:
    int sumOfMultiples(int n) {
        std::vector<int> multiples;
  for (int x = 1; x <= n; ++x) {
    if (x % 3 == 0 || x % 5 == 0 || x % 7 == 0) {
      multiples.push_back(x);
    }
  }
  return std::accumulate(multiples.begin(), multiples.end(), 0);
    }
};

class Solution:
    def sumOfMultiples(self, n: int) -> int:
        return sum([x for x in range(1,n+1) if (x%5 == 0) or (x%3 == 0) or (x%7 == 0)])
        
