class Solution {
public:
    int dp[1001][101][2];
    int solve(vector<int>& prices, int idx, int k, int buy)
    {
        if(idx == prices.size() || k == 0)
            return 0;
        if(dp[idx][k][buy] != -1)
            return dp[idx][k][buy];
        if(buy == 0)
        {
            return dp[idx][k][buy] = max(-prices[idx] + solve(prices, idx+1, k, 1), solve(prices, idx+1, k, 0));
        }
        else return dp[idx][k][buy] = max(prices[idx] + solve(prices, idx+1, k-1, 0), solve(prices, idx+1, k, 1));
    }
    
    int maxProfit(int k, vector<int>& prices) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, k, 0);
    }
};