//599. Minimum Index Sum of Two Lists
/*
Given two arrays of strings list1 and list2, find the common strings with the least index sum.
A common string is a string that appeared in both list1 and list2.
A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.
Return all the common strings with the least index sum. Return the answer in any order.
*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::set<std::string> set1(list1.begin(),list1.end());
        std::set<std::string> set2(list2.begin(),list2.end());
        std::vector<std::string> inter{};
        std::set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),std::back_inserter(inter));
        //std::cout << inter[0] << '\n';
        if(1 == inter.size())
            return inter;
        int m = INT_MAX;
        std::map<int,std::vector<std::string> > mp{};
        std::multiset<int> mset{};
        for(std::string s : inter)
        {
            auto p = std::find(list1.begin(),list1.end(),s);
            int d1 = std::distance(list1.begin(),p);
            
            auto q = std::find(list2.begin(),list2.end(),s);
            int d2 = std::distance(list2.begin(),q);
            
            mp[d1+d2].push_back(s);
            mset.insert(d1+d2); 
        }

        auto it = mset.begin();
        
        return mp[*it];
    }
};
