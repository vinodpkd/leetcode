//1331. Rank Transform of an Array
/*
Given an array of integers arr, replace each element with its rank.
The rank represents how large the element is. The rank has the following rules:
    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      std::map<int, int> rankMap;
    std::vector<int> sortedArr = arr;
    std::vector<int> result(arr.size());
    std::sort(sortedArr.begin(), sortedArr.end());

    int rank = 1;
    for (int i = 0; i < sortedArr.size(); ++i) {
        if (rankMap.find(sortedArr[i]) == rankMap.end()) {
            rankMap[sortedArr[i]] = rank++;
        }
    }

    for (int i = 0; i < arr.size(); ++i) {
        result[i] = rankMap[arr[i]];
    }

    return result;
    }
};

#include <bits/stdc++.h>

void print(std::vector<int>& nums)
{
	std::cout << '[';
	for(int x: nums)
		std::cout << x << ' ';
	std::cout << "]\n";
}
std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::vector<int> s(arr.begin(),arr.end());
		
        std::sort(s.begin(),s.end());
		std::unique(s.begin(),s.end());
		std::cout << "sorted\n";
		print(s);
        std::vector<int> rank(arr.size(),0);
        for(int i = 0;i < arr.size();i++)
        {
            auto it = std::find(s.begin(),s.end(),arr[i]);
            rank[i] = std::distance(s.begin(),it)+1;
        }
        return rank;
    }

int main() {
   
	std::vector<int> v{37,12,28,9,100,56,80,5,12};
	
	std::vector<int> w = arrayRankTransform(v);
	
	print(w);

    return 0;
}
