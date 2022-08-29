class Solution {
public:
    int dp[2][50001];
    int solve(vector<int>& prices, int fee, int buy, int idx)
    {
        if(idx == prices.size())
            return 0;
        if(dp[buy][idx] != -1)
            return dp[buy][idx];
        if(buy == 0)
            return dp[buy][idx] = max(-prices[idx] + solve(prices, fee, 1, idx+1), solve(prices, fee, 0, idx+1));
        else
            return dp[buy][idx] = max(+prices[idx] - fee + solve(prices, fee, 0, idx+1), solve(prices, fee, 1, idx+1));
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, fee, 0, 0);
    }
};