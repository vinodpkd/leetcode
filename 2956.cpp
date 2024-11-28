//2956. Find Common Elements Between Two Arrays,Incomplete


class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        
    }

    int sum_all_indices(vector<int>& A,int el)
    {
        

    std::vector<int>::iterator iter = A.begin();
    int index_sum {0};
    while ((iter = std::find_if(iter, A.end(), isZero)) != A.end())
    {
        // Do something with iter
        index_sum += std::distance(A.begin(),iter);
        iter++;
    }

    return index_sum;
    }
};
