//2657. Find the Prefix Common Array of Two Arrays
/*
You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
Return the prefix common array of A and B.
A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        std::vector<int> common{};
        std::vector<int> all{};
        for(int i = 0;i < A.size();i++)
        {
            std::set<int> s(A.begin(),A.begin()+1+i);
            std::set<int> t(B.begin(),B.begin()+1+i);

            std::set_intersection(s.begin(),s.end(),t.begin(),t.end(),std::back_inserter(common));
            //int size = common.size();
            all.push_back(common.size());
            common.clear();

        }

        return all;
    }
};
