//3271. Hash Divided String 100% beats in time
/*
You are given a string s of length n and an integer k, where n is a multiple of k. Your task is to hash the string s into a new string called result, which has a length of n / k.

First, divide s into n / k 
substrings
, each with a length of k. Then, initialize result as an empty string.

For each substring in order from the beginning:

The hash value of a character is the index of that character in the English alphabet (e.g., 'a' → 0, 'b' → 1, ..., 'z' → 25).
Calculate the sum of all the hash values of the characters in the substring.
Find the remainder of this sum when divided by 26, which is called hashedChar.
Identify the character in the English lowercase alphabet that corresponds to hashedChar.
Append that character to the end of result.
Return result.
*/
class Solution {
public:
    string stringHash(string s, int k) {
        std::string hash{""};
        for(int i = 0;i < s.length()/k;i++)
        {
            int sum{0};
            for(int j = 0;j < k;j++)
            {
                sum += s[i*k+j] - 'a';
            }

            sum = sum % 26;

            std::string a{(char)((int)'a' + sum)};

            hash += a;

        }

        return hash;
    }
};
