//2053. Kth Distinct String in an Array
/*
A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.
*/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::set<string> s(arr.begin(),arr.end());
        std::multiset<string> ms(arr.begin(),arr.end());
        std::vector<string> res{};
        std::set_difference(ms.begin(),ms.end(),s.begin(),s.end(),std::inserter(res,res.end()));
        std::vector<string> res2{};
        std::set_difference(s.begin(),s.end(),res.begin(),res.end(),std::inserter(res2,res2.end()));

        if(res2.size() < k)
            return "";

        std::multimap<int,std::string> mmap{};
        
        for(int i = 0;i < res2.size();i++)
        {
            auto it = std::find(arr.begin(),arr.end(),res2[i]);
            int ind = std::distance(arr.begin(),it);
            mmap.insert(std::make_pair(ind, res2[i]));
        }
        int i = 1;
        for(auto& x : mmap)
        {
            if(k == i)
                return x.second;
            i++;
        }

        //std::vector<int> 
        return "s";

    }
};
