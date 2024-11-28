//2418. Sort the People
/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
For each index i, names[i] and heights[i] denote the name and height of the ith person.
Return names sorted in descending order by the people's heights.
 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //To sort by value, make the value as key
      std::multimap<int,std::string> mmap{};
        for(int i = 0;i < heights.size();i++)
        {
            mmap.insert({heights[i], names[i]});
        }

        std::vector<std::string> sorted{};
      //To sort a map/multimap by its value, pair.second is inserted at 0 index, since multimap is sorted ascending by default.
        for(const std::pair<int,std::string> p : mmap)
        {
            sorted.insert(sorted.begin(),p.second);
        }

        return sorted;
    }
};
