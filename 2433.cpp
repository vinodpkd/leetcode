//2433. Find The Original Array of Prefix Xor
/*
You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:
    pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
Note that ^ denotes the bitwise-xor operation.
*/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n);
        res[0] = pref[0]; // The first element is the same as the first prefix XOR.

        for (int i = 1; i < n; ++i) {
            res[i] = pref[i - 1] ^ pref[i]; // XOR the current prefix XOR with the previous one.
        }
        return res;
    }
};
