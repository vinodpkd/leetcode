//1475. Final Prices With a Special Discount in a Shop
/*
You are given an integer array prices where prices[i] is the price of the ith item in a shop.
There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.
Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.
*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        std::vector<int> d(prices);
        for(int i = 0;i < prices.size();i++)
        {
            int c = prices[i];
            auto it = std::find_if(prices.begin()+i+1,prices.end(),[c](int n){return n <= c;});     if(it != prices.end())
                d[i] = prices[i] - *it;
            else
                d[i] = prices[i];
        }

        return d;
    }
};
