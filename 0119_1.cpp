//119. Pascal's Triangle II
/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> res{};
        if(0 == rowIndex)
        {
            res.push_back(1);
            return res;
        }
        for(int i = 0;i <= rowIndex;i++)
        {
            res.push_back(nchoosek(rowIndex,i));
        }

        return res;
    }

    int nchoosek(int n, int k)
{
	if(0 == k || n == k)
		return 1;
	k = (n-k) < k ? (n-k) : k;
	std::vector<int> divisors(k-1);
	std::iota(divisors.begin(),divisors.end(),2);
	
	std::vector<int> dividends(k,0);
	for(int i = 0;i < k;i++)
		dividends[i] = n-i;

	for(int i = 0;i < k;i++)
	{
		int j = 0;
		while(!divisors.empty() && j < divisors.size())
		{
			if(dividends[i] % divisors[j] == 0)
			{
				dividends[i] = dividends[i]/divisors[j];
				divisors.erase(divisors.begin()+j);
				continue;
			}
			j++;	
		}
	}
	
	int num = std::accumulate(dividends.begin(),dividends.end(),1,std::multiplies<int>{});

    //print(divisors);
	if(!divisors.empty())		
	{
		int den = std::accumulate(divisors.begin(),divisors.end(),1,std::multiplies<int>{});
		num = num/den;
	}
    
	return num;
	
}
};
