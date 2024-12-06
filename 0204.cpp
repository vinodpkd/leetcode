//204. Count Primes
/*
Given an integer n, return the number of prime numbers that are strictly less than n.
*/

#include <bits/stdc++.h>


void print(std::vector<int> nums)
{
	for(int x : nums)
		std::cout << x << ' ';
	std::cout << '\n';
}


int main()
{	
	int n = 499979;
	
	const auto time1 = std::chrono::high_resolution_clock::now();
	
	std::vector<int> v(n-2);
	std::iota(v.begin(),v.end(),2);
	
	int count{0};
	
	while(!v.empty())
	{
		int nextel = v[0];
	
		//std::cout << "Next element to be removed : " << nextel << '\n';
		
		/* v.erase(std::remove_if(v.begin(), 
								  v.end(),
								  [nextel](int a){return (a % nextel) == 0;}),
				   v.end()); */

		std::erase_if(v,[nextel](int a){return (a % nextel) == 0;}); //c++20

		count++;
		//print(v);
	}
	
	const auto time2 = std::chrono::high_resolution_clock::now();
	
	std::cout << "No of prime numbers less than n = " << n << " is " << count << '\n';
	
	
	
	
	std::cout << (time2 - time1).count() << '\n';
	
	
	return 0;
}
-------------------------
class Solution {
public:
    int countPrimes(int n) {
        // If n is 2 or less, there are no primes less than n
        if (n <= 2) return 0;
        
        // Create a boolean vector to mark non-prime numbers
        // Initially all numbers are considered prime
        vector<bool> isPrime(n, true);
        
        // 0 and 1 are not prime
        isPrime[0] = isPrime[1] = false;
        
        // Use Sieve of Eratosthenes to mark non-prime numbers
        // We only need to check up to sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Mark multiples of i as non-prime
                // Start from i*i as smaller multiples would have been 
                // marked by smaller prime factors already
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Count the number of prime numbers
        int primeCount = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                primeCount++;
            }
        }
        
        return primeCount;
    }
};
