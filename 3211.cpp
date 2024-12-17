//3211. Generate Binary Strings Without Adjacent Zeros
/*
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
    The 2D array should contain only the elements of the array nums.
    Each row in the 2D array contains distinct integers.
    The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.
Note that the 2D array can have a different number of elements on each row.
*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        std::multiset<int> ms(nums.begin(),nums.end());
        std::map<int,int,std::greater<> > mp{};
        std::multimap<int,int,std::greater<> > mlp{};
		
        for(auto it = ms.begin();it != ms.end();it++)
        {
            mp[*it]++;
        }

        for(auto& x : mp)
        {
            mlp.insert(std::make_pair(x.second, x.first));
        }
		
		std::vector<int> key(mlp.size(),0);
		std::vector<int> freq(mlp.size(),0);

        
		std::pair<int,int> itr = *mlp.begin();
        int rsize = itr.first;
        std::vector<std::vector<int> > res{};
		
		for(int i = 0;i < rsize;i++)
		{
			std::vector<int> temp{};
			res.push_back(temp);
		}
		
		//std::cout << "rsize = " << rsize << '\n';
		//std::cout << "rsize = " << res.size() << '\n';
		
		int k = 0;
		for(auto& kv : mlp)
		{
			key[k] = kv.first;
			freq[k] = kv.second;
			k++;
		}
		
		//print(key);
		//print(freq);
		
		
        for(int i = 0;i < freq.size();i++)
        {
            for(int j = 0;j < key[i];j++)
            {
                res[j].push_back(freq[i]);
            }
        }
		

        return res;

    }
};
