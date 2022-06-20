//O(n)
//O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;
        for(int i = 0; i<prices.size(); i++)
        {
            if(min_price > prices[i])
            {
                min_price = prices[i];
            }
            else if(prices[i] - min_price > profit)
                profit = prices[i] - min_price;
        }
        return profit;
    }
};