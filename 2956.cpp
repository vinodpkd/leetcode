//2956. Find Common Elements Between Two Arrays,Incomplete


class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        int answer1{0};

        for(int i = 0;i < nums1.size();i++)
        {
            answer1 += sum_all_indices(nums2,nums1[i]);
        }

        int answer2{0};
        
        for(int i = 0;i < nums2.size();i++)
        {
            answer2 += sum_all_indices(nums1,nums2[i]);
        }
        
        return {answer1,answer2};
    }

    int sum_all_indices(std::vector<int>& A,int el)
{
	std::vector<int>::iterator iter = A.begin();
	auto cond = [el](int num){return num == el;};
	int index_sum {0};
	//find all occurences of el in A
	while ((iter = std::find_if(iter, A.end(), cond)) != A.end())
	{
		// Do something with iter
		index_sum = 1;//std::distance(A.begin(),iter);
		iter++;
        break;
	}

	return index_sum;
}
};
