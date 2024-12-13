//119. Pascal's Triangle II
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
            res.push_back(choose(rowIndex,i));
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

int choose(int n, int k)
    {
        long int nn = n;
        if (k == 0)
            return 1;
        return (nn * choose(nn - 1, k - 1)) / k;
    }
};
