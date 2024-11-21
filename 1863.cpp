//1863. Sum of All Subset XOR Totals
//Incomplete
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        if(nums.empty())
            return 0;

        int xortotal = std::accumulate(nums.begin(),nums.end(),0);

     

        for(int k = 2;k < nums.size();k++)
	{    
		std::vector<std::vector<int>> all_comb = next_combination(nums, k);
		
		for(std::vector<int> x :all_comb)
		{
			
			int xortotal_now = 0;

			for(int i = 0;i < x.size();i++)
			{
				xortotal_now = xortotal_now ^ x[i];
			}

            xortotal += xortotal_now;
		}
	}

        return xortotal;

    }

    template <typename T>
std::vector<std::vector<int>> next_combination(std::vector<T>& data, int k) {
	
	std::vector<std::vector<int>> all_comb{};
	
    if (k <= 0 || k > data.size()) return all_comb;

    std::vector<int> indices(k);
    for (int i = 0; i < k; ++i) indices[i] = i;

    while (true) {
        // Process the combination
        std::vector<T> combination;
        for (int index : indices) combination.push_back(data[index]);

		all_comb.push_back(combination);

        int i = k - 1;
        while (i >= 0 && indices[i] == data.size() - k + i) --i;
        if (i < 0) break; // No more combinations

        ++indices[i];
        for (int j = i + 1; j < k; ++j) indices[j] = indices[j - 1] + 1;
    }
	
	return all_comb;
}
};


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        
	int n = nums.size();
        int totalXORSum = 0;

        for (int i = 0; i < (1 << n); ++i) { // Iterate through all possible subsets
            int currentXOR = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) { // Check if j-th bit is set in i (indicating element inclusion)
                    currentXOR ^= nums[j];
                }
            }
            totalXORSum += currentXOR;
        }
        return totalXORSum;

    }

    
