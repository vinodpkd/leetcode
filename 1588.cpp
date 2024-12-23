//1588. Sum of All Odd Length Subarrays
/*
Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.
A subarray is a contiguous subsequence of the array.
*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int s{0};
        for(int i = 0;i < arr.size();i++)
        {
            for(int j = i;j < arr.size();j++)
            {
                if((j-i+1)%2 == 1)
                {
                    s += std::accumulate(arr.begin()+i,arr.begin()+j+1,0);
                }
            }
        }

        return s;
    }
};
