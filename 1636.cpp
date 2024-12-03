//1636. Sort Array by Increasing Frequency
/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::map<int,int> freq{};
        bool dec{false};
        for(int i = 0;i < nums.size();i++)
        {
            freq[nums[i]]++;                 
        }
        std::multiset<int> mset{};
        for(std::pair x : freq)
        {
            mset.insert(x.second);
        }

        std::set<int> set1(mset.begin(),mset.end());

        if(set1.size() != mset.size())
            dec = true;

        std::cout << " dec = " << dec << '\n';

        std::multimap<int,int> vmap{};

        for(std::pair x : freq)
            vmap.insert({x.second, x.first});

        std::vector<int> sorted{};

        for(std::pair x : vmap)
        {
            for(int j = 0;j < x.first;j++)
                sorted.push_back(x.second);
        }

        return sorted;
        
    }
};
